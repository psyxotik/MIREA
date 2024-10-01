import sqlite3

def create_db_users():
    conn = sqlite3.connect('database\db.sqlite3')
    cursor = conn.cursor()
    cursor.execute('''CREATE TABLE IF NOT EXISTS users (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        username TEXT NOT NULL,
        password TEXT NOT NULL,
        age INTEGER NOT NULL,
        money INTEGER NOT NULL,
        income INTEGER NOT NULL,
        house_id INTEGER NOT NULL,
        FOREIGN KEY (house_id) REFERENCES houses (id)
    )''')
    conn.commit()
    conn.close()

def add_user(username, password, age, money, income):
    conn = sqlite3.connect('database\db.sqlite3')
    cursor = conn.cursor()
    cursor.execute('''INSERT INTO users (username, password, age, money, income, house_id)
                      VALUES (?, ?, ?, ?, ?, ?)''', (username, password, age, money, income, 0))
    conn.commit()
    conn.close()

def check_user_credentials(username, password):
    conn = sqlite3.connect('database\db.sqlite3')
    cursor = conn.cursor()
    cursor.execute('SELECT * FROM users WHERE username = ? AND password = ?', (username, password))
    user = cursor.fetchone()
    conn.close()
    return user is not None

def create_db_houses():
    conn = sqlite3.connect('database\db.sqlite3')
    cursor = conn.cursor()
    cursor.execute('''CREATE TABLE IF NOT EXISTS houses (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        name TEXT NOT NULL,
        price INTEGER NOT NULL,
        area INTEGER NOT NULL,
        is_big BOOLEAN NOT NULL,
        with_ending BOOLEAN NOT NULL,
        user_id INTEGER NOT NULL,
        FOREIGN KEY (user_id) REFERENCES users (id)
    )''')

def add_house(name, price, area, is_big, with_ending, user_id=0):
    conn = sqlite3.connect('database\db.sqlite3')
    cursor = conn.cursor()
    cursor.execute('''INSERT INTO houses (name, price, area, is_big, with_ending, user_id)
                      VALUES (?, ?, ?, ?, ?, ?)''', (name, price, area, is_big, with_ending, user_id))
    house_id = cursor.lastrowid
    conn.commit()
    conn.close()
    return house_id

def get_houses():
    conn = sqlite3.connect('database\db.sqlite3')
    cursor = conn.cursor()
    cursor.execute('SELECT id, name, price, area, is_big, with_ending FROM houses WHERE user_id = 0')
    houses = [{'id': row[0], 'name': row[1], 'price': row[2], 'area': row[3], 'is_big': row[4], 'with_ending': row[5]} for row in cursor.fetchall()]
    conn.close()
    return houses

def buy_house(user_id, house_id):
    conn = sqlite3.connect('database\db.sqlite3')
    cursor = conn.cursor()
    try:
        # Обновляем дом, устанавливая ему владельца
        cursor.execute('UPDATE houses SET user_id = ? WHERE id = ?', (user_id, house_id))
        
        # Обновляем пользователя, устанавливая ему дом
        cursor.execute('UPDATE users SET house_id = ? WHERE id = ?', (house_id, user_id))
        
        conn.commit()
    except sqlite3.Error as e:
        print(f"An error occurred: {e.args[0]}")
        conn.rollback()
    finally:
        conn.close()

def get_user_info(username):
    conn = sqlite3.connect('database\db.sqlite3')
    cursor = conn.cursor()
    cursor.execute('SELECT id, money FROM users WHERE username = ?', (username,))
    user = cursor.fetchone()
    conn.close()
    return {'id': user[0], 'money': user[1]}

def update_user_money(user_id, new_money):
    conn = sqlite3.connect('database\db.sqlite3')
    cursor = conn.cursor()
    cursor.execute('UPDATE users SET money = ? WHERE id = ?', (new_money, user_id))
    conn.commit()
    conn.close()


def get_human_info(user_id):
    conn = sqlite3.connect('database\db.sqlite3')
    cursor = conn.cursor()
    cursor.execute('SELECT username, age, money FROM users WHERE id = ?', (user_id,))
    user = cursor.fetchone()
    conn.close()
    return {'username': user[0], 'age': user[1], 'money': user[2]}

def get_user_houses(user_id):
    conn = sqlite3.connect('database\db.sqlite3')
    cursor = conn.cursor()
    cursor.execute('SELECT id FROM houses WHERE user_id = ?', (user_id,))
    houses = [row[0] for row in cursor.fetchall()]
    conn.close()
    return houses

def update_user_house(user_id, house_id):
    conn = sqlite3.connect('database\db.sqlite3')
    cursor = conn.cursor()
    cursor.execute('UPDATE users SET house_id = ? WHERE id = ?', (house_id, user_id))
    conn.commit()
    conn.close()