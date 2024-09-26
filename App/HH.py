from db import add_house, create_db_houses, add_user, get_human_info, update_user_money, update_user_house, get_user_houses


class House:
    def __init__(self, name, area, price, ending=False, user_id=0):
        self.name = name
        self._area = area
        self.__price = price
        self.is_ended = ending
        self.db = create_db_houses()
        self.id = add_house(name, price, area, True, ending, user_id)

    def final_price(self, discount):
        return self.__price * (1 - discount)


class SmallHouse(House):
    def __init__(self,name, price, ending=False, user_id=0):
        super().__init__(name, 40, price, ending, user_id)
        self.id = add_house(name, price, 40, False, ending, user_id)


class Human:
    default_name = "Нет имени"
    default_age = 30

    def __init__(self, name=default_name, age=default_age, id=None):
        if id is None:
            self.id = add_user(name, "default_password", age, 0, 0)
        else:
            self.id = id
        user_info = get_human_info(self.id)
        self.name = user_info['username']
        self.age = user_info['age']
        self.__money = user_info['money']
        self.__house = get_user_houses(self.id)

    def info(self):
        house_info = "Есть дом" if self.__house else "Нет дома"
        print(f'Информация о пользователе <{self.name}>:\nВозраст - {self.age} {check_age(self.age)} \nсбережения - {self.__money} \n'
              f'Дом - {house_info}')

    @staticmethod
    def default_info():
        print(f"Имя по умолчанию: {Human.default_name}, Возраст по умолчанию: {Human.default_age} {check_age(Human.default_age)}")

    def __make_deal(self, house, price):
        self.__money -= price
        self.__house.append(house)
        update_user_money(self.id, self.__money)
        update_user_house(self.id, house.id)

    def earn_money(self, profit):
        self.__money += profit
        update_user_money(self.id, self.__money)
        print(f"Заработано: {profit}. Теперь денег: {self.__money}")

    def buy_house(self, house, discount=0.0):
        if self.age < 18:
            print(f'Нельзя купить дом будучи несовершеннолетним')
        else:
            final_price = house.final_price(discount)

            if final_price <= self.__money:
                self.__make_deal(house, final_price)
                print(f"Дом площадью {house._area} м2 успешно куплен за {final_price}")
            else:
                print(f'нехватает денег для совершения сделки, окончательная цена дома: {final_price} вам нехватает:'
                      f' {final_price - self.__money}')

def check_age(age):
    if age < 18:
        return "Несовершеннолетний"
    elif 18 <= age < 65:
        return "Взрослый"
    else:
        return "Пожилой"


