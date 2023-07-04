import mysql.connector

connection = mysql.connector.connect(host = 'localhost', database = 'cse4701s20_project2', user = 'root', password = 'cse4701')
if connection.is_connected():
    cursor = connection.cursor(buffered = True)
    cursor.execute("SELECT database();")

quit = 0
while(quit == 0):
    print("Main Menu")
    print("1 - Create Account")
    print("2 - Balance")
    print("0 - Quit")
    print("Enter your choice:")

    choice = int(input())        
    if(choice == 0):
        quit = 1
    elif(choice == 1):
        print()
        print("Name on account:")
        name_on_account = str(input())
        print("Enter Initial Balance:")
        balance = input()

        sql = "INSERT INTO account (name_on_account, balance) VALUES (%s, %s)"
        val = (name_on_account, balance)
        cursor.execute(sql, val)
        connection.commit()

        sql = "SELECT account_no, account_open_date FROM account WHERE account_no = (SELECT MAX(account_no) FROM account)"
        cursor.execute(sql)
        result = cursor.fetchone()
        
        print()
        print("---Account successfully created---")
        print("Account number: {}".format(result[0]))
        print("Name on account: {}".format(name_on_account))
        print("Balance: {}".format(balance))
        print("Account opened on: {}".format(result[1]))
        print("----------------------------------")
    elif(choice == 2):
        print()
        print("Enter account number:")
        account_no = input()
        print()
        
        sql = "SELECT account_no, name_on_account, balance, account_open_date FROM account WHERE account_no = " + str(account_no)
        cursor.execute(sql)
        result = cursor.fetchone()

        if(result != None):
            print("---Checking account balance---")
            print("Account number: {}".format(result[0]))
            print("Name on account: {}".format(result[1]))
            print("Balance: {}".format(result[2]))
            print("Account opened on: {}".format(result[3]))
            print("------------------------------")
        else:
            print("Invalid account number")
    else:
        print("Invalid input")

    if(choice != 0):
        print()
                

