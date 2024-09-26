import sys
from PyQt5 import uic
from PyQt5.QtWidgets import QApplication, QMainWindow, QMessageBox, QTableWidgetItem, QHeaderView
from PyQt5.QtCore import Qt
from db import *

class Registration(QMainWindow):
    def __init__(self):
        super(Registration, self).__init__()
        uic.loadUi('Registration_Login.ui', self)
        self.Registration_button.clicked.connect(self.register_user)
        self.Login_button.clicked.connect(self.login_user)

    def register_user(self):
        username = self.Username_input_registration.text()
        password = self.Password_input_registration.text()
        password_confirm = self.Password_confirm_input_registration.text()
        age = self.age_input_registration.value()
        money = self.Current_money_input_registrarion.value()
        income = self.income_input_registration.value()

        if not all([username, password, password_confirm, age, money, income]):
            QMessageBox.warning(self, "Ошибка", "Пожалуйста, заполните все поля")
            return

        if password != password_confirm:
            QMessageBox.warning(self, "Ошибка", "Пароли не совпадают")
            return

        if age < 18:
            QMessageBox.warning(self, "Ошибка", "Регистрация возможна только с 18 лет")
            return

        # Добавление пользователя в базу данных
        create_db_users()  # Убедимся, что таблица существует
        add_user(username, password, age, money, income)
        QMessageBox.information(self, "Успех", "Регистрация прошла успешно")
    
    def login_user(self):
        username = self.Username_input_login_checker.text()
        password = self.Password_input_login_checker.text()

        if check_user_credentials(username, password):
            self.main_window = MainWindow(username)
            self.main_window.show()
            self.close()
        else:
            QMessageBox.warning(self, "Ошибка", "Неверный логин или пароль")



class MainWindow(QMainWindow):
    def __init__(self, username):
        super(MainWindow, self).__init__()
        uic.loadUi('main_window.ui', self)
        self.username = username
        self.user_info = get_user_info(username)
        self.setup_ui()
        self.load_houses()
        
    def setup_ui(self):
        self.Current_user.setText(self.username)
        self.Current_money.setText(f"Деньги: {self.user_info['money']}")
        self.Buy_button.setEnabled(False)
        self.Buy_button.clicked.connect(self.buy_house)
        self.exit_button.clicked.connect(self.exit_to_login)
        self.Home_view.itemClicked.connect(self.enable_buy_button)
        self.with_finishing_radbutton.toggled.connect(self.filter_houses)
        self.without_finishing_radButton.toggled.connect(self.filter_houses)
        self.small_home_radButton.toggled.connect(self.filter_houses)
        self.big_home_radButton.toggled.connect(self.filter_houses)
        self.clear_filter_check.stateChanged.connect(self.filter_houses)
        self.budget_checker.stateChanged.connect(self.filter_houses)
        
    def load_houses(self):
        self.houses = get_houses()
        self.Home_view.setColumnCount(4)
        self.Home_view.setHorizontalHeaderLabels(["Название", "Площадь", "Цена", "Отделка"])
        self.Home_view.setRowCount(len(self.houses))
        for row, house in enumerate(self.houses):
            self.Home_view.setItem(row, 0, QTableWidgetItem(house['name']))
            self.Home_view.setItem(row, 1, QTableWidgetItem(str(house['area'])))
            self.Home_view.setItem(row, 2, QTableWidgetItem(str(house['price'])))
            self.Home_view.setItem(row, 3, QTableWidgetItem("Есть" if house['with_ending'] else "Нет"))
        self.Home_view.horizontalHeader().setSectionResizeMode(QHeaderView.Stretch)
        
    def enable_buy_button(self):
        self.Buy_button.setEnabled(True)
        
    def buy_house(self):
        selected_row = self.Home_view.currentRow()
        if selected_row >= 0:
            house = self.houses[selected_row]
            house_name = house['name']
            house_price = house['price']
            house_id = house['id']
            user_money = self.user_info['money']

            if house_price <= user_money:
                self.process_purchase(house_id, house_name, house_price)
            elif house_price <= user_money * 1.05:  # Если не хватает до 5%
                discounted_price = house_price * 0.95
                reply = QMessageBox.question(self, 'Предложение скидки',
                                            f"Вам не хватает {house_price - user_money} для покупки дома '{house_name}'.\n"
                                            f"Хотите купить его со скидкой 5% за {discounted_price}?",
                                            QMessageBox.Да | QMessageBox.Нет, QMessageBox.Нет)
                if reply == QMessageBox.Да:
                    self.process_purchase(house_id, house_name, discounted_price)
                else:
                    QMessageBox.information(self, "Отказ", "Вы отказались от покупки со скидкой.")
            else:
                QMessageBox.warning(self, "Ошибка", "У вас недостаточно денег для покупки этого дома.")

    def process_purchase(self, house_id, house_name, price):
        reply = QMessageBox.question(self, 'Подтверждение покупки', 
                                    f"Вы уверены, что хотите купить дом '{house_name}' за {price}?",
                                    QMessageBox.Да | QMessageBox.Нет, QMessageBox.Нет)
        if reply == QMessageBox.Да:
            buy_house(self.user_info['id'], house_id)
            self.user_info['money'] -= price
            update_user_money(self.user_info['id'], self.user_info['money'])
            self.Current_money.setText(f"Деньги: {self.user_info['money']}")
            self.load_houses()
            QMessageBox.information(self, "Успех", "Дом успешно куплен!")
        
    def filter_houses(self):
        if self.clear_filter_check.isChecked():
            # Очищаем все фильтры
            self.with_finishing_radbutton.setChecked(False)
            self.without_finishing_radButton.setChecked(False)
            self.small_home_radButton.setChecked(False)
            self.big_home_radButton.setChecked(False)
            self.budget_checker.setChecked(False)
            # Показываем все строки
            for row in range(self.Home_view.rowCount()):
                self.Home_view.setRowHidden(row, False)
        else:
            for row in range(self.Home_view.rowCount()):
                show_row = True
                if self.with_finishing_radbutton.isChecked():
                    show_row = show_row and self.Home_view.item(row, 3).text() == "Есть"
                if self.without_finishing_radButton.isChecked():
                    show_row = show_row and self.Home_view.item(row, 3).text() == "Нет"
                if self.small_home_radButton.isChecked():
                    show_row = show_row and int(self.Home_view.item(row, 1).text()) <= 40
                if self.big_home_radButton.isChecked():
                    show_row = show_row and int(self.Home_view.item(row, 1).text()) > 40
                if self.budget_checker.isChecked():
                    house_price = int(self.Home_view.item(row, 2).text())
                    show_row = show_row and house_price <= self.user_info['money']
                self.Home_view.setRowHidden(row, not show_row)
        
    def exit_to_login(self):
        self.close()
        self.login_window = Registration()
        self.login_window.show()



app = QApplication(sys.argv)
ex = Registration()
ex.show()
sys.exit(app.exec_())
