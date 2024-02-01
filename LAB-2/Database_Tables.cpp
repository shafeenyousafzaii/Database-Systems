
CREATE TABLE THEMEPARK (
PARK_CODE VARCHAR(10) PRIMARY KEY,
PARK_NAME VARCHAR(35) NOT NULL,
PARK_CITY VARCHAR(50) NOT NULL,
PARK_COUNTRY CHAR(2) NOT NULL);


CREATE TABLE EMPLOYEE(
EMP_NUM NUMERIC(4) PRIMARY KEY,
EMP_TITLE VARCHAR(4),
EMP_LNAME VARCHAR(15) NOT NULL,
EMP_FNAME VARCHAR(15) NOT NULL,
EMP_DOB DATE NOT NULL,
EMP_HIRE_DATE DATE,
EMP_AREA_CODE VARCHAR(4) NOT NULL,
EMP_PHONE VARCHAR(12)NOT NULL,
PARK_CODE VARCHAR(10),
INDEX (PARK_CODE),
CONSTRAINT FK_EMP_PARK FOREIGN KEY(PARK_CODE) REFERENCES THEMEPARK(PARK_CODE));

CREATE TABLE TICKET (
TICKET_NO NUMERIC(10) PRIMARY KEY,
TICKET_PRICE VARCHAR(10),
TICKET_TYPE VARCHAR(10),
PARK_CODE VARCHAR(10),
INDEX (PARK_CODE),
CONSTRAINT FK_TICKET_PARK FOREIGN KEY(PARK_CODE) REFERENCES THEMEPARK(PARK_CODE));

CREATE TABLE ATTRACTION (
ATTRACT_NO NUMERIC(10) PRIMARY KEY,
ATTRACT_NAME VARCHAR(35),
ATTRACT_AGE NUMERIC(3) DEFAULT 0 NOT NULL,
ATTRACT_CAPACITY NUMERIC(3) NOT NULL,
PARK_CODE VARCHAR(10),
INDEX (PARK_CODE),
CONSTRAINT FK_ATTRACT_PARK FOREIGN KEY(PARK_CODE) REFERENCES THEMEPARK(PARK_CODE));

CREATE TABLE HOURS (
EMP_NUM NUMERIC(4),
ATTRACT_NO NUMERIC(10),
HOURS_PER_ATTRACT NUMERIC(2) NOT NULL,
HOUR_RATE NUMERIC(4,2) NOT NULL,
DATE_WORKED DATE NOT NULL,
INDEX (EMP_NUM),
INDEX (ATTRACT_NO),
CONSTRAINT PK_HOURS PRIMARY KEY (EMP_NUM, ATTRACT_NO, DATE_WORKED),
CONSTRAINT FK_HOURS_EMP FOREIGN KEY (EMP_NUM) REFERENCES EMPLOYEE(EMP_NUM),
CONSTRAINT FK_HOURS_ATTRACT FOREIGN KEY (ATTRACT_NO) REFERENCES ATTRACTION(ATTRACT_NO));

CREATE TABLE SALES (
TRANSACTION_NO NUMERIC PRIMARY KEY,
PARK_CODE VARCHAR(10),
SALE_DATE DATE NOT NULL,
INDEX (PARK_CODE),
CONSTRAINT FK_SALES_PARK FOREIGN KEY(PARK_CODE) REFERENCES THEMEPARK(PARK_CODE));

CREATE TABLE SALES_LINE (
TRANSACTION_NO NUMERIC,
LINE_NO NUMERIC(2,0) NOT NULL,
TICKET_NO NUMERIC(10) NOT NULL,
LINE_QTY NUMERIC(4) DEFAULT 0 NOT NULL,
LINE_PRICE NUMERIC(9,2) DEFAULT 0.00 NOT NULL,
INDEX (TRANSACTION_NO),
INDEX (TICKET_NO),
CONSTRAINT PK_SALES_LINE PRIMARY KEY (TRANSACTION_NO, LINE_NO),
CONSTRAINT FK_SALES_LINE_SALES FOREIGN KEY (TRANSACTION_NO) REFERENCES SALES(TRANSACTION_NO),
CONSTRAINT FK_SALES_LINE_TICKET FOREIGN KEY (TICKET_NO) REFERENCES TICKET(TICKET_NO));


INSERT INTO TICKET VALUES (13001,18.99,'FR1001')
INSERT INTO TICKET VALUES (13002,34.99,'FR1001')
INSERT INTO TICKET VALUES (13003,20.99,'FR1001')
INSERT INTO TICKET VALUES (88567,22.50,'UK3452')
INSERT INTO TICKET VALUES (88568,42.10,'UK3452')
INSERT INTO TICKET VALUES (89720,10.99,'UK3452')


INSERT INTO THEMEPARK VALUES ('FR1001', 'FairyLand', 'PARIS', 'FR');
INSERT INTO THEMEPARK VALUES ('NL1202', 'Efling', 'NOORD', 'IN');
INSERT INTO THEMEPARK VALUES ('SP4533', 'Adventure Port', 'BARCELONA', 'SP');
INSERT INTO THEMEPARK VALUES ('SW2323', 'Labyrinthe', 'LAUSANNE', 'SV');
INSERT INTO THEMEPARK VALUES ('UK2622', 'MiniLand', 'WINDSOR', 'UK');
INSERT INTO THEMEPARK VALUES ('UK3452', 'PleasureLand', 'STOKE', 'UK');
INSERT INTO THEMEPARK VALUES ('ZA1342', 'GoldTown', 'JOHANNESBURG', 'ZA');



INSERT INTO ATTRACTION VALUES (10034, 'ThunderCoaster',18, 34,'FR1001');
INSERT INTO ATTRACTION VALUES (10056, 'SpinningTeacups',16, 62,'FR1001');
INSERT INTO ATTRACTION VALUES (10067, 'FlightToStars', 32,24,'SP4533');
INSERT INTO ATTRACTION VALUES (18878, 'Ant-Trap', 12,30,'ZA1342');
INSERT INTO ATTRACTION VALUES (10082, NULL,42, 40,'FR1001');
INSERT INTO ATTRACTION VALUES (10098, 'Carnival', 8,120,'ZA1342');
INSERT INTO ATTRACTION VALUES (20056, '3D-Lego_Show',12, 200,'FR1001');
INSERT INTO ATTRACTION VALUES (30011, 'BlackHole2', 16,34,'UK2622');
INSERT INTO ATTRACTION VALUES (30012, 'Pirates', 15,42,'UK2622');
INSERT INTO ATTRACTION VALUES (30044, 'UnderSeaWord',16, 80,'SP4533');
INSERT INTO ATTRACTION VALUES (98764, 'Gold Rush', 17,1,'FR1001');


INSERT INTO EMPLOYEE VALUES (1234, 'Mr.','Doe','John','2000-01-01','2021-01-01','123','123-456-7890','FR1001');
INSERT INTO EMPLOYEE VALUES (5678, 'Mrs.','Smith','Jane','1995-05-15','2020-02-15','456','987-654-3210','NL1202');
INSERT INTO EMPLOYEE VALUES(9101, 'Dr.','Johnson','Robert' ,'1980-12-05','2018-08-10','789','555-123-4567','FR1001');
INSERT INTO EMPLOYEE VALUES (2222, 'Miss','Williams','Emily','1992-08-23','2017-06-20','321','333-444-5555','NL1202');
INSERT INTO EMPLOYEE VALUES (3333, 'Mr.','Brown','Michael' ,'1985-04-10','2015-12-03','555','888-777-9999','FR1001');
INSERT INTO EMPLOYEE VALUES (4444, 'Ms.','Davis','Sophia','1990-07-07','2016-09-25','666','222-111-3333','SP4533');
INSERT INTO EMPLOYEE VALUES (5555, 'Dr.','Lee','Andrew','1978-11-30','2014-03-12','888','444-555-6666','SW2323');
INSERT INTO EMPLOYEE VALUES(6666, 'Mrs.','Taylor','Olivia','1988-02-18','2013-07-08','999','777-888-0000','UK2622');
INSERT INTO EMPLOYEE VALUES(7777, 'Mr.','Harris','David','1997-06-05','2012-05-22','111','666-333-9999','UK3452');
INSERT INTO EMPLOYEE VALUES (8888, 'Miss','Garcia','Isabella','1983-09-12','2011-10-18','444','999-222-1111','ZA1342');


INSERT INTO EMPLOYEE VALUES (2049,'Mr','Rahat','Noman','1990-12-20','2015-5-5','7253','502-493-5555','UK3452');


// i mistakenly changed all FNAMES into one so i am changin it back
UPDATE EMPLOYEE
SET EMP_FNAME = 'John'
WHERE EMP_NUM = 1234;

UPDATE EMPLOYEE
SET EMP_FNAME = 'Emily'
WHERE EMP_NUM = 2222;

UPDATE EMPLOYEE
SET EMP_FNAME = 'Michael'
WHERE EMP_NUM = 3333;

UPDATE EMPLOYEE
SET EMP_FNAME = 'Sophia'
WHERE EMP_NUM = 4444;

UPDATE EMPLOYEE
SET EMP_FNAME = 'Andrew'
WHERE EMP_NUM = 5555;

UPDATE EMPLOYEE
SET EMP_FNAME = 'Jane'
WHERE EMP_NUM = 5678;

UPDATE EMPLOYEE
SET EMP_FNAME = 'Olivia'
WHERE EMP_NUM = 6666;

UPDATE EMPLOYEE
SET EMP_FNAME = 'David'
WHERE EMP_NUM = 7777;

UPDATE EMPLOYEE
SET EMP_FNAME = 'Isabella'
WHERE EMP_NUM = 8888;

UPDATE EMPLOYEE
SET EMP_FNAME = 'Robert'
WHERE EMP_NUM = 9101;

UPDATE EMPLOYEE
SET EMP_FNAME = 'DAVID'
WHERE EMP_NUM = 9101;



|    1234 | Mr.       | Doe       | John      | 2000-01-01 | 2021-01-01    | 123           | 123-456-7890 | FR1001    |
|    2222 | Miss      | Williams  | Emily     | 1992-08-23 | 2017-06-20    | 321           | 333-444-5555 | NL1202    |
|    3333 | Mr.       | Brown     | Michael   | 1985-04-10 | 2015-12-03    | 555           | 888-777-9999 | FR1001    |
|    4444 | Ms.       | Davis     | Sophia    | 1990-07-07 | 2016-09-25    | 666           | 222-111-3333 | SP4533    |
|    5555 | Dr.       | Lee       | Andrew    | 1978-11-30 | 2014-03-12    | 888           | 444-555-6666 | SW2323    |
|    5678 | Mrs.      | Smith     | Jane      | 1995-05-15 | 2020-02-15    | 456           | 987-654-3210 | NL1202    |
|    6666 | Mrs.      | Taylor    | Olivia    | 1988-02-18 | 2013-07-08    | 999           | 777-888-0000 | UK2622    |
|    7777 | Mr.       | Harris    | David     | 1997-06-05 | 2012-05-22    | 111           | 666-333-9999 | UK3452    |
|    8888 | Miss      | Garcia    | Isabella  | 1983-09-12 | 2011-10-18    | 444           | 999-222-1111 | ZA1342    |
|    9101 | Dr.       | Johnson   | Robert    | 1980-12-05 | 2018-08-10    | 789           | 555-123-4567 | FR1001    |


Park
Code
PK2049
Park
Name
Garrison
Park City
Park
Country
Peshawar PK

INSERT INTO THEMEPARK VALUES ('PK2049', 'Garrison', 'Peshawar', 'PK');

// THIS IS THE ALL THE TASK DONE ON TERMIANL

(anaconda3)shafeen@shafeen-Dell-G15-5515:~$ fish
Welcome to fish, the friendly interactive shell
Type help for instructions on how to use fish
shafeen@shafeen-Dell-G15-5515 ~> mysql -u root -p
Enter password: 
ERROR 1698 (28000): Access denied for user 'root'@'localhost'
shafeen@shafeen-Dell-G15-5515 ~ [1]> sudo mysql -u root
[sudo] password for shafeen: 
Sorry, try again.
[sudo] password for shafeen: 
Welcome to the MariaDB monitor.  Commands end with ; or \g.
Your MariaDB connection id is 32
Server version: 10.11.6-MariaDB-0ubuntu0.23.10.2 Ubuntu 23.10

Copyright (c) 2000, 2018, Oracle, MariaDB Corporation Ab and others.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

MariaDB [(none)]> USE mysql
Reading table information for completion of table and column names
You can turn off this feature to get a quicker startup with -A

Database changed
MariaDB [mysql]> show databases;
+--------------------+
| Database           |
+--------------------+
| fast               |
| fast_dbms          |
| information_schema |
| mysql              |
| performance_schema |
| sys                |
+--------------------+
6 rows in set (0.000 sec)

MariaDB [mysql]> SHOW databases;
+--------------------+
| Database           |
+--------------------+
| fast               |
| fast_dbms          |
| information_schema |
| mysql              |
| performance_schema |
| sys                |
+--------------------+
6 rows in set (0.000 sec)

MariaDB [mysql]> CREATE database THEME_PARK:
    -> ;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near ':' at line 1
MariaDB [mysql]> CREATE database THEME_PARK;
Query OK, 1 row affected (0.000 sec)

MariaDB [mysql]> SHOW databases;
+--------------------+
| Database           |
+--------------------+
| THEME_PARK         |
| fast               |
| fast_dbms          |
| information_schema |
| mysql              |
| performance_schema |
| sys                |
+--------------------+
7 rows in set (0.000 sec)

MariaDB [mysql]> clear
MariaDB [mysql]> 
MariaDB [mysql]> 
MariaDB [mysql]> ;


















































MariaDB [mysql]> CREATE TABLE THEMEPARK(
    -> ;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near '' at line 1
MariaDB [mysql]> SHOW databases;l
+--------------------+
| Database           |
+--------------------+
| THEME_PARK         |
| fast               |
| fast_dbms          |
| information_schema |
| mysql              |
| performance_schema |
| sys                |
+--------------------+
7 rows in set (0.000 sec)

    -> l
    -> ;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'l
l' at line 1
MariaDB [mysql]> SHOW databases;
+--------------------+
| Database           |
+--------------------+
| THEME_PARK         |
| fast               |
| fast_dbms          |
| information_schema |
| mysql              |
| performance_schema |
| sys                |
+--------------------+
7 rows in set (0.000 sec)

MariaDB [mysql]> USE THEME_PARK;
Database changed
MariaDB [THEME_PARK]> SHOW DATABASES;
+--------------------+
| Database           |
+--------------------+
| THEME_PARK         |
| fast               |
| fast_dbms          |
| information_schema |
| mysql              |
| performance_schema |
| sys                |
+--------------------+
7 rows in set (0.000 sec)

MariaDB [THEME_PARK]> USE mysql
Reading table information for completion of table and column names
You can turn off this feature to get a quicker startup with -A

Database changed
MariaDB [mysql]> ;
ERROR: No query specified

MariaDB [mysql]> CREATE DATABASE THEME_PARK2
    -> l
    -> ;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'l' at line 2
MariaDB [mysql]> CREATE DATABASE THEME_PARK2 l;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'l' at line 1
MariaDB [mysql]> CREATE DATABASE THEME_PARK2;
Query OK, 1 row affected (0.000 sec)

MariaDB [mysql]> SHOW DATABASES;
+--------------------+
| Database           |
+--------------------+
| THEME_PARK         |
| THEME_PARK2        |
| fast               |
| fast_dbms          |
| information_schema |
| mysql              |
| performance_schema |
| sys                |
+--------------------+
8 rows in set (0.000 sec)

MariaDB [mysql]> USE THEME_PARK2
Database changed
MariaDB [THEME_PARK2]> USE THEME_PARK;
Database changed
MariaDB [THEME_PARK]> CREATE TABLE THEMEPARK (
    -> PARK_CODE VARCHAR(10) PRIMARY KEY,
    -> PARK_NAME VARCHAR(35) NOT NULL,
    -> PARK_CITY VARCHAR(50) NOT NULL,
    -> PARK_COUNTRY CHAR(2) NOT NULL);
Query OK, 0 rows affected (0.014 sec)

MariaDB [THEME_PARK]> SHOW tables
    -> ;
+----------------------+
| Tables_in_THEME_PARK |
+----------------------+
| THEMEPARK            |
+----------------------+
1 row in set (0.000 sec)

MariaDB [THEME_PARK]> CREATE TABLE THEME_PARK(
    -> ;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near '' at line 1
MariaDB [THEME_PARK]> DELETE TABLE THEMEPARK
    -> ;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'TABLE THEMEPARK' at line 1
MariaDB [THEME_PARK]> DROP TABLE THEMEPARK;
Query OK, 0 rows affected (0.011 sec)

MariaDB [THEME_PARK]> SHOW TABLE THEMEPARK;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'THEMEPARK' at line 1
MariaDB [THEME_PARK]> SHOW TABLES;
Empty set (0.000 sec)

MariaDB [THEME_PARK]> CREATE TABLE THEME_PARK(
    -> PARK_CODE VARCHAR(10)PRIMARY KEY,
    -> PARK_NAME VARCHAR(35)NOT NULL,
    -> PARK_CITY VARCHAR(50)NOT NULL<
    -> PARK_CITY VARCHAR(50)NOT NULL,
    -> PARK_COUNTRY CHAR(2)NOT NULL);
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near '<
PARK_CITY VARCHAR(50)NOT NULL,
PARK_COUNTRY CHAR(2)NOT NULL)' at line 4
MariaDB [THEME_PARK]> CREATE TABLE THEME_PARK( PARK_CODE VARCHAR(10)PRIMARY KEY, PARK_NAME VARCHAR(35)NOT NULL, PARK_CITY VARCHAR(50)NOT NULL, PARK_COUNTRY CHAR(2)NOT NULL);
Query OK, 0 rows affected (0.011 sec)

MariaDB [THEME_PARK]> SHOW TABLES
    -> ;
+----------------------+
| Tables_in_THEME_PARK |
+----------------------+
| THEME_PARK           |
+----------------------+
1 row in set (0.000 sec)

MariaDB [THEME_PARK]> CREATE TABLE EMPLOYEE(
    -> EMP_NUM NUMERIC(4)PRIMARY KEY;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near '' at line 2
MariaDB [THEME_PARK]> CREATE TABLE EMPLOYEE( EMP_NUM NUMERIC(4)PRIMARY KEY, EMP_TITLE VARCHAR(4), EMP_LNAME VARHCAR(15)NOT NULL, EMP_FNAME VARHCAR(15)NOT NULL, EMP_DOB DATE NOT NULL, EMP_HIRE_DATE DATE, EMP_AREA_CODE VARCAHR(4)NOT NULL, EMP_PHONE VARCHAR(12)NOT NULL, PARK_CODE VARCHAR(10), INDEX(PARK_CODE), CONSTRAINT FK_EMP_PARK FOREIGN KEY (PARK_CODE) REFERENCES THEMEPARK(PARK_CODE));
ERROR 4161 (HY000): Unknown data type: 'VARHCAR'
MariaDB [THEME_PARK]> CREATE TABLE EMPLOYEE( EMP_NUM NUMERIC(4)PRIMARY KEY, EMP_TITLE VARCHAR(4), EMP_LNAME VARHCAR(15)NOT NULL, EMP_FNAME VARHCAR(15)NOT NULL, EMP_DOB DATE NOT NULL, EMP_HIRE_DATE DATE, EMP_AREA_CODE VARCAHR(4)NOT NULL, EMP_PHONE VARCHAR(12)Nfish: Job 1, 'sudo mysql -u root' has stoppedDDDDRK_CODE), CONSTRAINT FK_EMP_PARK FOREIGN KEY (PARK_CODE) REFERENCES THEMshafeen@shafeen-Dell-G15-5515 ~ [1]> sudo mysql -u root
[sudo] password for shafeen: 
Welcome to the MariaDB monitor.  Commands end with ; or \g.
Your MariaDB connection id is 33
Server version: 10.11.6-MariaDB-0ubuntu0.23.10.2 Ubuntu 23.10

Copyright (c) 2000, 2018, Oracle, MariaDB Corporation Ab and others.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

MariaDB [(none)]> USE THEME_PARK
Reading table information for completion of table and column names
You can turn off this feature to get a quicker startup with -A

Database changed
MariaDB [THEME_PARK]> show tables;l
+----------------------+
| Tables_in_THEME_PARK |
+----------------------+
| THEME_PARK           |
+----------------------+
1 row in set (0.000 sec)

    -> show tables;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'l
show tables' at line 1
MariaDB [THEME_PARK]> l show tables;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'l show tables' at line 1
MariaDB [THEME_PARK]> show tables;
+----------------------+
| Tables_in_THEME_PARK |
+----------------------+
| THEME_PARK           |
+----------------------+
1 row in set (0.000 sec)

MariaDB [THEME_PARK]> CREATE TABLE EMPLOYEE (
    -> EMP_NUM NUMERIC(4) PRIMARY KEY,
    -> EMP_TITLE VARCHAR(4),
    -> EMP_LNAME VARCHAR(15) NOT NULL,
    -> EMP_FNAME VARCHAR(15) NOT NULL,
    -> EMP_DOB DATE NOT NULL,
    -> EMP_HIRE_DATE DATE,
    -> EMP_AREA_CODE VARCHAR(4) NOT NULL,
    -> EMP_PHONE VARCHAR(12) NOT NULL,
    -> PARK_CODE VARCHAR(10),
    -> INDEX (PARK_CODE),
    -> CONSTRAINT FK_EMP_PARK FOREIGN KEY(PARK_CODE) REFERENCES
    -> THEMEPARK(PARK_CODE));
ERROR 1005 (HY000): Can't create table `THEME_PARK`.`EMPLOYEE` (errno: 150 "Foreign key constraint is incorrectly formed")
MariaDB [THEME_PARK]> CREATE TABLE EMPLOYEE (
    -> EMP_NUM NUMERIC(4) PRIMARY KEY,
    -> EMP_TITLE VARCHAR(4),
    -> EMP_LNAME VARCHAR(15) NOT NULL,
    -> EMP_FNAME VARCHAR(15) NOT NULL,
    -> EMP_DOB DATE NOT NULL,
    -> EMP_HIRE_DATE DATE,
    -> EMP_AREA_CODE VARCHAR(4) NOT NULL,
    -> EMP_PHONE VARCHAR(12) NOT NULL,
    -> PARK_CODE VARCHAR(10),
    -> INDEX (PARK_CODE),
    -> CONSTRAINT FK_EMP_PARK FOREIGN KEY(PARK_CODE) REFERENCES
    -> THffish: Job 2, 'sudo mysql -u root' has stopped
shafeen@shafeen-Dell-G15-5515 ~ [1]> sudo mysql -u root
Welcome to the MariaDB monitor.  Commands end with ; or \g.
Your MariaDB connection id is 34
Server version: 10.11.6-MariaDB-0ubuntu0.23.10.2 Ubuntu 23.10

Copyright (c) 2000, 2018, Oracle, MariaDB Corporation Ab and others.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

MariaDB [(none)]> fish: Job 3, 'sudo mysql -u root' has stopped
shafeen@shafeen-Dell-G15-5515 ~ [1]> fish
Welcome to fish, the friendly interactive shell
Type help for instructions on how to use fish
shafeen@shafeen-Dell-G15-5515 ~> sudo mysql -u root
Welcome to the MariaDB monitor.  Commands end with ; or \g.
Your MariaDB connection id is 35
Server version: 10.11.6-MariaDB-0ubuntu0.23.10.2 Ubuntu 23.10

Copyright (c) 2000, 2018, Oracle, MariaDB Corporation Ab and others.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

MariaDB [(none)]> use fast_dbms
Database changed
MariaDB [fast_dbms]> SHOW DATABASES;
+--------------------+
| Database           |
+--------------------+
| THEME_PARK         |
| THEME_PARK2        |
| fast               |
| fast_dbms          |
| information_schema |
| mysql              |
| performance_schema |
| sys                |
+--------------------+
8 rows in set (0.000 sec)

MariaDB [fast_dbms]> use THEME_PARK;
Reading table information for completion of table and column names
You can turn off this feature to get a quicker startup with -A

Database changed
MariaDB [THEME_PARK]> show databases;
+--------------------+
| Database           |
+--------------------+
| THEME_PARK         |
| THEME_PARK2        |
| fast               |
| fast_dbms          |
| information_schema |
| mysql              |
| performance_schema |
| sys                |
+--------------------+
8 rows in set (0.000 sec)

MariaDB [THEME_PARK]> show tables;
+----------------------+
| Tables_in_THEME_PARK |
+----------------------+
| THEME_PARK           |
+----------------------+
1 row in set (0.000 sec)

MariaDB [THEME_PARK]> CREATE TABLE EMPLOYEE (
    -> EMP_NUM NUMERIC(4) PRIMARY KEY,
    -> EMP_TITLE VARCHAR(4),
    -> EMP_LNAME VARCHAR(15) NOT NULL,
    -> EMP_FNAME VARCHAR(15) NOT NULL,
    -> EMP_DOB DATE NOT NULL,
    -> EMP_HIRE_DATE DATE,
    -> EMP_AREA_CODE VARCHAR(4) NOT NULL,
    -> EMP_PHONE VARCHAR(12) NOT NULL,
    -> PARK_CODE VARCHAR(10),
    -> INDEX (PARK_CODE),
    -> CONSTRAINT FK_EMP_PARK FOREIGN KEY(PARK_CODE) REFERENCES
    -> Ctrl-C -- exit!
Aborted
shafeen@shafeen-Dell-G15-5515 ~ [1]> sudo mysql -u root
Welcome to the MariaDB monitor.  Commands end with ; or \g.
Your MariaDB connection id is 36
Server version: 10.11.6-MariaDB-0ubuntu0.23.10.2 Ubuntu 23.10

Copyright (c) 2000, 2018, Oracle, MariaDB Corporation Ab and others.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

MariaDB [(none)]> show THEME_PARK;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'THEME_PARK' at line 1
MariaDB [(none)]> USE THEME_PARK;
Reading table information for completion of table and column names
You can turn off this feature to get a quicker startup with -A

Database changed
MariaDB [THEME_PARK]> CREATE TABLE EMPLOYEE (
    -> EMP_NUM NUMERIC(4) PRIMARY KEY,
    -> EMP_TITLE VARCHAR(4),
    -> EMP_LNAME VARCHAR(15) NOT NULL,
    -> EMP_FNAME VARCHAR(15) NOT NULL,
    -> EMP_DOB DATE NOT NULL,
    -> EMP_HIRE_DATE DATE,
    -> EMP_AREA_CODE VARCHAR(4) NOT NULL,
    -> EMP_PHONE VARCHAR(12) NOT NULL,
    -> PARK_CODE VARCHAR(10),
    -> INDEX (PARK_CODE),
    -> CREATE TABLE EMPLOYEE (
    -> EMP_NUM NUMERIC(4) PRIMARY KEY,
    -> EMP_TITLE VARCHAR(4),
    -> EMP_LNAME VARCHAR(15) NOT NULL,
    -> EMP_FNAME VARCHAR(15) NOT NULL,
    -> EMP_DOB DATE NOT NULL,
    -> EMP_HIRE_DATE DATE,
    -> EMP_AREA_CODE VARCHAR(4) NOT NULL,
    -> EMP_PHONE VARCHAR(12) NOT NULL,
    -> PARK_CODE VARCHAR(10),
    -> INDEX (PARK_CODE),fish: Job 1, 'sudo mysql -u root' has stopped
shafeen@shafeen-Dell-G15-5515 ~ [1]> sudo mysql -u root
Welcome to the MariaDB monitor.  Commands end with ; or \g.
Your MariaDB connection id is 37
Server version: 10.11.6-MariaDB-0ubuntu0.23.10.2 Ubuntu 23.10

Copyright (c) 2000, 2018, Oracle, MariaDB Corporation Ab and others.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

MariaDB [(none)]> USE THEME_PARK;
Reading table information for completion of table and column names
You can turn off this feature to get a quicker startup with -A

Database changed
MariaDB [THEME_PARK]> CREATE TABLE EMPLOYEE (
    -> EMP_NUM NUMERIC(4) PRIMARY KEY,
    -> EMP_TITLE VARCHAR(4),
    -> EMP_LNAME VARCHAR(15) NOT NULL,
    -> EMP_FNAME VARCHAR(15) NOT NULL,
    -> EMP_DOB DATE NOT NULL,
    -> EMP_HIRE_DATE DATE,
    -> EMP_AREA_CODE VARCHAR(4) NOT NULL,
    -> EMP_PHONE VARCHAR(12) NOT NULL,
    -> PARK_CODE VARCHAR(10),
    -> INDEX (PARK_CODE),
    -> CONSTRAINT FK_EMP_PARK FOREIGN KEY(PARK_CODE) REFERENCES THEMEPARK(PARK_CODE));
ERROR 1005 (HY000): Can't create table `THEME_PARK`.`EMPLOYEE` (errno: 150 "Foreign key constraint is incorrectly formed")
MariaDB [THEME_PARK]> CREATE TABLE EMPLOYEE ( EMP_NUM NUMERIC(4) PRIMARY KEY, EMP_TITLE VARCHAR(4), EMP_LNAME VARCHAR(15) NOT NULL, EMP_FNAME VARCHAR(15) NOT NULL, EMP_DOB DATE NOT NULL, EMP_HIRE_DATE DATE, EMP_AREA_CODE VARCHAR(4) NOT NULL, EMP_PHONE VARCHAR(12) NOT NULL, PARK_CODE VARCHAR(10), INDEX (PARK_CODE), CONSTRAINT FK_EMP_PARK FOREIGNKEY(PARK_CODE) REFERENCES THEMEPARK(PARK_CODE));
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'FOREIGNKEY(PARK_CODE) REFERENCES THEMEPARK(PARK_CODE))' at line 1
MariaDB [THEME_PARK]> CREATE TABLE EMPLOYEE ( EMP_NUM NUMERIC(4) PRIMARY KEY, EMP_TITLE VARCHAR(4), EMP_LNAME VARCHAR(15) NOT NULL, EMP_FNAME VARCHAR(15) NOT NULL, EMP_DOB DATE NOT NULL, EMP_HIRE_DATE DATE, EMP_AREA_CODE VARCHAR(4) NOT NULL, EMP_PHONE VARCHAR(12) NOT NULL, PARK_CODE VARCHAR(10), INDEX (PARK_CODE), CONSTRAINT FK_EMP_PARK FOREIGN KEY(PARK_CODE) REFERENCES THEMEPARK(PARK_CODE));
ERROR 1005 (HY000): Can't create table `THEME_PARK`.`EMPLOYEE` (errno: 150 "Foreign key constraint is incorrectly formed")
MariaDB [THEME_PARK]> CREATE TABLE EMPLOYEE (
    -> EMP_NUM NUMERIC(4) PRIMARY KEY,
    -> EMP_TITLE VARCHAR(4),
    -> EMP_LNAME VARCHAR(15) NOT NULL,
    -> EMP_FNAME VARCHAR(15) NOT NULL,
    -> EMP_DOB DATE NOT NULL,
    -> EMP_HIRE_DATE DATE,
    -> EMP_AREA_CODE VARCHAR(4) NOT NULL,
    -> EMP_PHONE VARCHAR(12) NOT NULL,
    -> PARK_CODE VARCHAR(10),
    -> INDEX (PARK_CODE),
    -> CONSTRAINT FK_EMP_PARK FOREIGN KEY(PARK_CODE) REFERENCES THEMEPARK(PARK_CODE));
ERROR 1005 (HY000): Can't create table `THEME_PARK`.`EMPLOYEE` (errno: 150 "Foreign key constraint is incorrectly formed")
MariaDB [THEME_PARK]> CREATE TABLE EMPLOYEE(
    ->     -> EMP_NUM NUMERIC(4) PRIMARY KEY,
    ->     -> EMP_TITLE VARCHAR(4)
    ->     -> ,EMP_LNAME VARCHAR(15) NOT NULL,
    ->     -> EMP_FNAME VARCHAR(15) NOT NULL,
    ->     -> EMP_DOB DATE NOT NULL,
    ->     -> EMP_HIRE_DATE DATE,
    ->     -> EMP_AREA_CODE VARCHAR(4) NOT NULL,
    ->     -> EMP_PHONE VARCHAR(12)NOT NULL,
    ->     -> PARK_CODE VARCHAR(10),
    ->     -> INDEX (PAKR_CODE),
    ->     -> CONSTRAINT FK_EMP_PARK FOREIGN KEY(PARK_CODE) REFERENCES THEMEPARK(PARK_CODE));
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near '-> EMP_NUM NUMERIC(4) PRIMARY KEY,
    -> EMP_TITLE VARCHAR(4)
    -> ,EMP_LN...' at line 2
MariaDB [THEME_PARK]> CREATE TABLE EMPLOYEE(
    ->     -> EMP_NUM NUMERIC(4) PRIMARY KEY,
    ->     -> EMP_TITLE VARCHAR(4)
    ->     -> ,EMP_LNAME VARCHAR(15) NOT NULL,
    ->     -> EMP_FNAME VARCHAR(15) NOT NULL,
    ->     -> EMP_DOB DATE NOT NULL,
    ->     -> EMP_HIRE_DATE DATE,
    ->     -> EMP_AREA_CODE VARCHAR(4) NOT NULL,
    ->     -> EMP_PHONE VARCHAR(12)NOT NULL,
    ->     -> PARK_CODE VARCHAR(10),
    ->     -> INDEX (PAKR_CODE),
    -> CONSTRAINT FK_EMP_PARK FOREIGN KEY(PARK_CODE) REFERENCES THEMEPARK(PARK_CODE));
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near '-> EMP_NUM NUMERIC(4) PRIMARY KEY,
    -> EMP_TITLE VARCHAR(4)
    -> ,EMP_LN...' at line 2
MariaDB [THEME_PARK]> CREATE TABLE EMPLOYEE(EMP_NUM NUMERIC(4) PRIMARY KEY, EMP_TITLE VARCHAR(4), EMP_LNAME VARCHAR(15) NOT NULL, EMP_FNAME VARCHAR(15) NOT NULL, EMP_DOB DATE NOT NULL, EMP_H                                                                                                                                                                                      EMEPARK(PARK_CODE));
ERROR 1072 (42000): Key column 'PAKR_CODE' doesn't exist in table
MariaDB [THEME_PARK]> CREATE TABLE EMPLOYEE(
    -> EMP_NUM NUMERIC(4) PRIMARY KEY,
    -> EMP_TITLE VARCHAR(4),
    -> EMP_LNAME VARCHAR(15) NOT NULL,
    -> EMP_FNAME VARCHAR(15) NOT NULL,
    -> EMP_DOB DATE NOT NULL,
    -> EMP_HIRE_DATE DATE,
    -> EMP_AREA_CODE VARCHAR(4) NOT NULL,
    -> EMP_PHONE VARCHAR(12)NOT NULL,
    -> PARK_CODE VARCHAR(10),
    -> INDEX (PAKR_CODE),
    -> CONSTRAINT FK_EMP_PARK FOREIGN KEY(PARK_CODE) REFERENCES THEMEPARK(PARK_CODE));
ERROR 1072 (42000): Key column 'PAKR_CODE' doesn't exist in table
MariaDB [THEME_PARK]> CREATE TABLE EMPLOYEE(
    -> EMP_NUM NUMERIC(4) PRIMARY KEY,
    -> EMP_TITLE VARCHAR(4),
    -> EMP_LNAME VARCHAR(15) NOT NULL,
    -> EMP_FNAME VARCHAR(15) NOT NULL,
    -> EMP_DOB DATE NOT NULL,
    -> EMP_HIRE_DATE DATE,
    -> EMP_AREA_CODE VARCHAR(4) NOT NULL,
    -> EMP_PHONE VARCHAR(12)NOT NULL,
    -> PARK_CODE VARCHAR(10),
    -> INDEX (PARK_CODE),
    -> CONSTRAINT FK_EMP_PARK FOREIGN KEY(PARK_CODE) REFERENCES THEMEPARK(PARK_CODE));
ERROR 1005 (HY000): Can't create table `THEME_PARK`.`EMPLOYEE` (errno: 150 "Foreign key constraint is incorrectly formed")
MariaDB [THEME_PARK]> CREATE TABLE EMPLOYEE(
    -> EMP_NUM NUMERIC(4) PRIMARY KEY,
    -> EMP_TITLE VARCHAR(4),
    -> EMP_LNAME VARCHAR(15) NOT NULL,
    -> EMP_FNAME VARCHAR(15) NOT NULL,
    -> EMP_DOB DATE NOT NULL,
    -> EMP_HIRE_DATE DATE,
    -> EMP_AREA_CODE VARCHAR(4) NOT NULL,
    -> EMP_PHONE VARCHAR(12)NOT NULL,
    -> PARK_CODE VARCHAR(10),
    -> INDEX (PARK_CODE),
    -> CONSTRAINT FK_EMP_PARK FOREIGN KEY(PARK_CODE) REFERENCES THEMEPARK(PARK_CODE));
ERROR 1005 (HY000): Can't create table `THEME_PARK`.`EMPLOYEE` (errno: 150 "Foreign key constraint is incorrectly formed")
MariaDB [THEME_PARK]> drop theme_park
    -> ;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'theme_park' at line 1
MariaDB [THEME_PARK]> DROP THEME_PARK
    -> ;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'THEME_PARK' at line 1
MariaDB [THEME_PARK]> SHOW databasesl
    -> ;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'databasesl' at line 1
MariaDB [THEME_PARK]> SHOW databases
    -> ;
+--------------------+
| Database           |
+--------------------+
| THEME_PARK         |
| THEME_PARK2        |
| fast               |
| fast_dbms          |
| information_schema |
| mysql              |
| performance_schema |
| sys                |
+--------------------+
8 rows in set (0.000 sec)

MariaDB [THEME_PARK]> DROP THEME_PARK;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'THEME_PARK' at line 1
MariaDB [THEME_PARK]> drop table THEME_PARK;
Query OK, 0 rows affected (0.008 sec)

MariaDB [THEME_PARK]> SHOW DATABASES;
+--------------------+
| Database           |
+--------------------+
| THEME_PARK         |
| THEME_PARK2        |
| fast               |
| fast_dbms          |
| information_schema |
| mysql              |
| performance_schema |
| sys                |
+--------------------+
8 rows in set (0.000 sec)

MariaDB [THEME_PARK]> DROP TABLE 
    -> ;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near '' at line 1
MariaDB [THEME_PARK]> SHOW TABLES;
Empty set (0.000 sec)

MariaDB [THEME_PARK]> CREATE TABLE THEMEPARK (
    -> PARK_CODE VARCHAR(10) PRIMARY KEY,
    -> PARK_NAME VARCHAR(35) NOT NULL,
    -> PARK_CITY VARCHAR(50) NOT NULL,
    -> PARK_COUNTRY CHAR(2) NOT NULL);
Query OK, 0 rows affected (0.011 sec)

MariaDB [THEME_PARK]> CREATE TABLE EMPLOYEE(
    -> EMP_NUM NUMERIC(4) PRIMARY KEY,
    -> EMP_TITLE VARCHAR(4),
    -> EMP_LNAME VARCHAR(15) NOT NULL,
    -> EMP_FNAME VARCHAR(15) NOT NULL,
    -> EMP_DOB DATE NOT NULL,
    -> EMP_HIRE_DATE DATE,
    -> EMP_AREA_CODE VARCHAR(4) NOT NULL,
    -> EMP_PHONE VARCHAR(12)NOT NULL,
    -> PARK_CODE VARCHAR(10),
    -> INDEX (PARK_CODE),
    -> CONSTRAINT FK_EMP_PARK FOREIGN KEY(PARK_CODE) REFERENCES THEMEPARK(PARK_CODE));
Query OK, 0 rows affected (0.014 sec)

MariaDB [THEME_PARK]> CREATE TABLE TICKET (
    -> TICKET_NO NUMERIC(10) PRIMARY KEY,
    -> TICKET_PRICE VARCHAR(10),
    -> PARK_CODE VARCHAR(10),
    -> INDEX (PARK_CODE),
    -> CONSTRAINT FK_TICKET_PARK FOREIGN KEY(PARK_CODE) REFERENCES THEMEPARK(PARK_CODE));
Query OK, 0 rows affected (0.015 sec)

MariaDB [THEME_PARK]> CREATE TABLE ATTRACTION (
    -> ATTRACT_NO NUMERIC(10) PRIMARY KEY,
    -> ATTRACT_NAME VARCHAR(35),
    -> ATTRACT_AGE NUMERIC(3) DEFAULT 0 NOT NULL,
    -> ATTRACT_CAPACITY NUMERIC(3) NOT NULL,
    -> PAKR_CODE VARCHAR(10),
    -> INDEX (PARK_CODE),
    -> CONSTRAINT FK_ATTRACT_PARK FOREIGN KEY(PARK_CODE) REFERENCES THEMEPARK(PARK_CODE));
ERROR 1072 (42000): Key column 'PARK_CODE' doesn't exist in table
MariaDB [THEME_PARK]> show TABLES;
+----------------------+
| Tables_in_THEME_PARK |
+----------------------+
| EMPLOYEE             |
| THEMEPARK            |
| TICKET               |
+----------------------+
3 rows in set (0.000 sec)

MariaDB [THEME_PARK]> CREATE TABLE ATTRACTION ( ATTRACT_NO NUMERIC(10) PRIMARY KEY, ATTRACT_NAME VARCHAR(35), ATTRACT_AGE NUMERIC(3) DEFAULT 0 NOT NULL, ATTRACT_CAPACITY NUMERIC(3) NOT NULL, PAKR_CODE VARCHAR(10), INDEX (PARK_CODE), CONSTRAINT FK_ATTRACT_PARK FOREIGN KEY(PARK_CODE) REFERENCES THEMEPARK(PARK_CODE)); 
ERROR 1072 (42000): Key column 'PARK_CODE' doesn't exist in table
MariaDB [THEME_PARK]> DESCRIBE EMPLOYEE;
+---------------+--------------+------+-----+---------+-------+
| Field         | Type         | Null | Key | Default | Extra |
+---------------+--------------+------+-----+---------+-------+
| EMP_NUM       | decimal(4,0) | NO   | PRI | NULL    |       |
| EMP_TITLE     | varchar(4)   | YES  |     | NULL    |       |
| EMP_LNAME     | varchar(15)  | NO   |     | NULL    |       |
| EMP_FNAME     | varchar(15)  | NO   |     | NULL    |       |
| EMP_DOB       | date         | NO   |     | NULL    |       |
| EMP_HIRE_DATE | date         | YES  |     | NULL    |       |
| EMP_AREA_CODE | varchar(4)   | NO   |     | NULL    |       |
| EMP_PHONE     | varchar(12)  | NO   |     | NULL    |       |
| PARK_CODE     | varchar(10)  | YES  | MUL | NULL    |       |
+---------------+--------------+------+-----+---------+-------+
9 rows in set (0.001 sec)

MariaDB [THEME_PARK]> DESCRIBE THEMEPARK
    -> 
    -> ;
+--------------+-------------+------+-----+---------+-------+
| Field        | Type        | Null | Key | Default | Extra |
+--------------+-------------+------+-----+---------+-------+
| PARK_CODE    | varchar(10) | NO   | PRI | NULL    |       |
| PARK_NAME    | varchar(35) | NO   |     | NULL    |       |
| PARK_CITY    | varchar(50) | NO   |     | NULL    |       |
| PARK_COUNTRY | char(2)     | NO   |     | NULL    |       |
+--------------+-------------+------+-----+---------+-------+
4 rows in set (0.001 sec)

MariaDB [THEME_PARK]> DESCRIBE TICKET;
+--------------+---------------+------+-----+---------+-------+
| Field        | Type          | Null | Key | Default | Extra |
+--------------+---------------+------+-----+---------+-------+
| TICKET_NO    | decimal(10,0) | NO   | PRI | NULL    |       |
| TICKET_PRICE | varchar(10)   | YES  |     | NULL    |       |
| PARK_CODE    | varchar(10)   | YES  | MUL | NULL    |       |
+--------------+---------------+------+-----+---------+-------+
3 rows in set (0.001 sec)

MariaDB [THEME_PARK]> SHOW databases;
+--------------------+
| Database           |
+--------------------+
| THEME_PARK         |
| THEME_PARK2        |
| fast               |
| fast_dbms          |
| information_schema |
| mysql              |
| performance_schema |
| sys                |
+--------------------+
8 rows in set (0.000 sec)

MariaDB [THEME_PARK]> SHOW tables;
+----------------------+
| Tables_in_THEME_PARK |
+----------------------+
| EMPLOYEE             |
| THEMEPARK            |
| TICKET               |
+----------------------+
3 rows in set (0.000 sec)

MariaDB [THEME_PARK]> CREATE TABLE ATTRACTION (
    -> ATTRACT_NO NUMERIC(10) PRIMARY KEY,
    -> ATTRACT_NAME VARCHAR(35),
    -> ATTRACT_AGE NUMERIC(3) DEFAULT 0 NOT NULL,
    -> ATTRACT_CAPACITY NUMERIC(3) NOT NULL,
    -> PARK_CODE VARCHAR(10),
    -> INDEX (PARK_CODE),
    -> CONSTRAINT FK_ATTRACT_PARK FOREIGN KEY(PARK_CODE) REFERENCES THEMEPARK(PARK_CODE));
Query OK, 0 rows affected (0.014 sec)

MariaDB [THEME_PARK]> show tables;
+----------------------+
| Tables_in_THEME_PARK |
+----------------------+
| ATTRACTION           |
| EMPLOYEE             |
| THEMEPARK            |
| TICKET               |
+----------------------+
4 rows in set (0.000 sec)

MariaDB [THEME_PARK]> CREATE TABLE HOURS (
    -> EMP_NUM NUMERIC(4),
    -> ATTRACT_NO NUMERIC(10),
    -> HOURS_PER_ATTRACT NUMERIC(2) NOT NULL,
    -> HOUR_RATE NUMERIC(4,2) NOT NULL,
    -> DATE_WORKED DATE NOT NULL,
    -> INDEX (EMP_NUM),
    -> INDEX (ATTRACT_NO),
    -> CONSTRAINT PK_HOURS PRIMARY KEY (EMP_NUM, ATTRACT_NO, DATE_WORKED),
    -> CONSTRAINT FK_HOURS_EMP FOREIGN KEY (EMP_NUM) REFERENCES EMPLOYEE(EMP_NUM),
    -> CONSTRAINT FK_HOURS_ATTRACT FOREIGN KEY (ATTRACT_NO) REFERENCES ATTRACTION(ATTRACT_NO));
Query OK, 0 rows affected, 1 warning (0.017 sec)

MariaDB [THEME_PARK]> show tables
    -> ;
+----------------------+
| Tables_in_THEME_PARK |
+----------------------+
| ATTRACTION           |
| EMPLOYEE             |
| HOURS                |
| THEMEPARK            |
| TICKET               |
+----------------------+
5 rows in set (0.000 sec)

MariaDB [THEME_PARK]> CREATE TABLE SALES (
    -> TRANSACTION_NO NUMERIC PRIMARY KEY,
    -> PARK_CODE VARCHAR(10),
    -> SALE_DATE DATE NOT NULL,
    -> INDEX (PARK_CODE),
    -> CONSTRAINT FK_SALES_PARK FOREIGN KEY(PARK_CODE) REFERENCES THEMEPARK(PARK_CODE));
Query OK, 0 rows affected (0.016 sec)

MariaDB [THEME_PARK]> show tables;
+----------------------+
| Tables_in_THEME_PARK |
+----------------------+
| ATTRACTION           |
| EMPLOYEE             |
| HOURS                |
| SALES                |
| THEMEPARK            |
| TICKET               |
+----------------------+
6 rows in set (0.000 sec)

MariaDB [THEME_PARK]> CREATE TABLE SALES_LINE (
    -> TRANSACTION_NONUMERIC,
    -> LINE_NON UMERIC(2,0) NOT NULL,
    -> TICKET_NO NUMERIC(10) NOT NULL,
    -> LINE_QTY NUMERIC(4) DEFAULT 0 NOT NULL,
    -> LINE_PRICE NUMERIC(9,2) DEFAULT 0.00 NOT NULL,
    -> INDEX (TRANSACTION_NO),
    -> INDEX (TICKET_NO),
    -> CONSTRAINT PK_SALES_LINE PRIMARY KEY (TRANSACTION_NO, LINE_NO),
    -> CONSTRAINT FK_SALES_LINE_SALES FOREIGN KEY (TRANSACTION_NO) REFERENCES SALES(TRANSACTION_NO),
    -> CONSTRAINT FK_SALES_LINE_TICKET FOREIGN KEY (TICKET_NO) REFERENCES TICKET(TICKET_NO));
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near '
LINE_NON UMERIC(2,0) NOT NULL,
TICKET_NO NUMERIC(10) NOT NULL,
LINE_QTY NUME...' at line 2
MariaDB [THEME_PARK]> CREATE TABLE SALES_LINE (
    -> TRANSACTION_NO NUMERIC,
    -> LINE_NON UMERIC(2,0) NOT NULL,
    -> TICKET_NO NUMERIC(10) NOT NULL,
    -> LINE_QTY NUMERIC(4) DEFAULT 0 NOT NULL,
    -> LINE_PRICE NUMERIC(9,2) DEFAULT 0.00 NOT NULL,
    -> INDEX (TRANSACTION_NO),
    -> INDEX (TICKET_NO),
    -> CONSTRAINT PK_SALES_LINE PRIMARY KEY (TRANSACTION_NO, LINE_NO),
    -> CONSTRAINT FK_SALES_LINE_SALES FOREIGN KEY (TRANSACTION_NO) REFERENCES SALES(TRANSACTION_NO),
    -> CONSTRAINT FK_SALES_LINE_TICKET FOREIGN KEY (TICKET_NO) REFERENCES TICKET(TICKET_NO));
ERROR 4161 (HY000): Unknown data type: 'UMERIC'
MariaDB [THEME_PARK]> CREATE TABLE SALES_LINE (
    -> TRANSACTION_NO NUMERIC,
    -> LINE_NO NUMERIC(2,0) NOT NULL,
    -> TICKET_NO NUMERIC(10) NOT NULL,
    -> LINE_QTY NUMERIC(4) DEFAULT 0 NOT NULL,
    -> LINE_PRICE NUMERIC(9,2) DEFAULT 0.00 NOT NULL,
    -> INDEX (TRANSACTION_NO),
    -> INDEX (TICKET_NO),
    -> CONSTRAINT PK_SALES_LINE PRIMARY KEY (TRANSACTION_NO, LINE_NO),
    -> CONSTRAINT FK_SALES_LINE_SALES FOREIGN KEY (TRANSACTION_NO) REFERENCES SALES(TRANSACTION_NO),
    -> CONSTRAINT FK_SALES_LINE_TICKET FOREIGN KEY (TICKET_NO) REFERENCES TICKET(TICKET_NO));
Query OK, 0 rows affected, 1 warning (0.017 sec)

MariaDB [THEME_PARK]> show tables
    -> ;
+----------------------+
| Tables_in_THEME_PARK |
+----------------------+
| ATTRACTION           |
| EMPLOYEE             |
| HOURS                |
| SALES                |
| SALES_LINE           |
| THEMEPARK            |
| TICKET               |
+----------------------+
7 rows in set (0.000 sec)

MariaDB [THEME_PARK]> exit
Bye
shafeen@shafeen-Dell-G15-5515 ~> sudo /opt/lampp/bin/mysqldump -u root -p THEME_PARK > /home/shafeen/Desktop/newthemepark.sql
[sudo] password for shafeen: 
Enter password: 
mysqldump: Got error: 2002: "Can't connect to local MySQL server through socket '/opt/lampp/var/mysql/mysql.sock' (2)" when trying to connect
shafeen@shafeen-Dell-G15-5515 ~ [2]> sudo /opt/lampp/bin/mysqldump -u root -p THEME_PARK > /home/shafeen/Desktop/newthemepark.sql
Enter password: 
mysqldump: Got error: 2002: "Can't connect to local MySQL server through socket '/opt/lampp/var/mysql/mysql.sock' (2)" when trying to connect
shafeen@shafeen-Dell-G15-5515 ~ [2]> sudo /opt/lampp/lampp status

Version: XAMPP for Linux 8.2.12-0
Apache is not running.
MySQL is not running.
ProFTPD is not running.
shafeen@shafeen-Dell-G15-5515 ~> sudo /opt/lampp/lampp startmysql

XAMPP: Starting MySQL...ok.
shafeen@shafeen-Dell-G15-5515 ~> sudo /opt/lampp/lampp startmysql

XAMPP: Starting MySQL...ok.
shafeen@shafeen-Dell-G15-5515 ~> ls /opt/lampp/var/mysql/mysql.sock

ls: cannot access '/opt/lampp/var/mysql/mysql.sock': No such file or directory
shafeen@shafeen-Dell-G15-5515 ~ [2]> sudo /opt/lampp/bin/mysqldump -u root -p THEME_PARK > /home/shafeen/Desktop/newthemepark.sql
Enter password: 
mysqldump: Got error: 2002: "Can't connect to local MySQL server through socket '/opt/lampp/var/mysql/mysql.sock' (2)" when trying to connect
shafeen@shafeen-Dell-G15-5515 ~ [2]> sudo /opt/lampp/lampp status

Version: XAMPP for Linux 8.2.12-0
Apache is not running.
MySQL is not running.
ProFTPD is not running.
shafeen@shafeen-Dell-G15-5515 ~> sudo /opt/lampp/lampp status

Version: XAMPP for Linux 8.2.12-0
Apache is not running.
MySQL is not running.
ProFTPD is not running.
shafeen@shafeen-Dell-G15-5515 ~> sudo /opt/lampp/lampp startmysql

XAMPP: Starting MySQL...ok.
shafeen@shafeen-Dell-G15-5515 ~> fish
Welcome to fish, the friendly interactive shell
Type help for instructions on how to use fish
shafeen@shafeen-Dell-G15-5515 ~> sudo systemctl status mysql
● mariadb.service - MariaDB 10.11.6 database server
     Loaded: loaded (/lib/systemd/system/mariadb.service; enabled; preset: enabled)
     Active: active (running) since Mon 2024-01-29 19:55:07 PKT; 1 day 3h ago
       Docs: man:mariadbd(8)
             https://mariadb.com/kb/en/library/systemd/
    Process: 1749 ExecStartPre=/usr/bin/install -m 755 -o mysql -g root -d /var/run/mysqld (code=exited, status=0/SUCCESS)
    Process: 1855 ExecStartPre=/bin/sh -c systemctl unset-environment _WSREP_START_POSITION (code=exited, status=0/SUCCESS)
    Process: 1899 ExecStartPre=/bin/sh -c [ ! -e /usr/bin/galera_recovery ] && VAR= ||   VAR=`cd /usr/bin/..; /usr/bin/galera_recovery`; [ $? -eq 0 ]   && systemctl set-environment _WSREP_S>
    Process: 2135 ExecStartPost=/bin/sh -c systemctl unset-environment _WSREP_START_POSITION (code=exited, status=0/SUCCESS)
    Process: 2137 ExecStartPost=/etc/mysql/debian-start (code=exited, status=0/SUCCESS)
   Main PID: 2008 (mariadbd)
     Status: "Taking your SQL requests now..."
      Tasks: 12 (limit: 37641)
     Memory: 112.5M
        CPU: 6.138s
     CGroup: /system.slice/mariadb.service
             └─2008 /usr/sbin/mariadbd

Jan 29 19:55:07 shafeen-Dell-G15-5515 mariadbd[2008]: 2024-01-29 19:55:07 0 [Note] Plugin 'FEEDBACK' is disabled.
Jan 29 19:55:07 shafeen-Dell-G15-5515 mariadbd[2008]: 2024-01-29 19:55:07 0 [Warning] You need to use --log-bin to make --expire-logs-days or --binlog-expire-logs-seconds work.
Jan 29 19:55:07 shafeen-Dell-G15-5515 mariadbd[2008]: 2024-01-29 19:55:07 0 [Note] InnoDB: Buffer pool(s) load completed at 240129 19:55:07
Jan 29 19:55:07 shafeen-Dell-G15-5515 mariadbd[2008]: 2024-01-29 19:55:07 0 [Note] Server socket created on IP: '127.0.0.1'.
Jan 29 19:55:07 shafeen-Dell-G15-5515 mariadbd[2008]: 2024-01-29 19:55:07 0 [Note] /usr/sbin/mariadbd: ready for connections.
Jan 29 19:55:07 shafeen-Dell-G15-5515 mariadbd[2008]: Version: '10.11.6-MariaDB-0ubuntu0.23.10.2'  socket: '/run/mysqld/mysqld.sock'  port: 3306  Ubuntu 23.10
Jan 29 19:55:07 shafeen-Dell-G15-5515 systemd[1]: Started mariadb.service - MariaDB 10.11.6 database server.
Jan 29 19:55:07 shafeen-Dell-G15-5515 /etc/mysql/debian-start[2139]: Upgrading MySQL tables if necessary.
Jan 29 19:55:07 shafeen-Dell-G15-5515 /etc/mysql/debian-start[2154]: Triggering myisam-recover for all MyISAM tables and aria-recover for all Aria tables
Jan 30 14:51:46 shafeen-Dell-G15-5515 mariadbd[2008]: 2024-01-30 14:51:46 31 [Warning] Access denied for user 'root'@'localhost'
shafeen@shafeen-Dell-G15-5515 ~ [SIGINT]> sudo systemct status mysql
sudo: systemct: command not found
shafeen@shafeen-Dell-G15-5515 ~ [1]> sudo systemctl status mysql
● mariadb.service - MariaDB 10.11.6 database server
     Loaded: loaded (/lib/systemd/system/mariadb.service; enabled; preset: enabled)
     Active: active (running) since Mon 2024-01-29 19:55:07 PKT; 1 day 3h ago
       Docs: man:mariadbd(8)
             https://mariadb.com/kb/en/library/systemd/
    Process: 1749 ExecStartPre=/usr/bin/install -m 755 -o mysql -g root -d /var/run/mysqld (code=exited, status=0/SUCCESS)
    Process: 1855 ExecStartPre=/bin/sh -c systemctl unset-environment _WSREP_START_POSITION (code=exited, status=0/SUCCESS)
    Process: 1899 ExecStartPre=/bin/sh -c [ ! -e /usr/bin/galera_recovery ] && VAR= ||   VAR=`cd /usr/bin/..; /usr/bin/galera_recovery`; [ $? -eq 0 ]   && systemctl set-environment _WSREP_S>
    Process: 2135 ExecStartPost=/bin/sh -c systemctl unset-environment _WSREP_START_POSITION (code=exited, status=0/SUCCESS)
    Process: 2137 ExecStartPost=/etc/mysql/debian-start (code=exited, status=0/SUCCESS)
   Main PID: 2008 (mariadbd)
     Status: "Taking your SQL requests now..."
      Tasks: 12 (limit: 37641)
     Memory: 112.5M
        CPU: 6.141s
     CGroup: /system.slice/mariadb.service
             └─2008 /usr/sbin/mariadbd

Jan 29 19:55:07 shafeen-Dell-G15-5515 mariadbd[2008]: 2024-01-29 19:55:07 0 [Note] Plugin 'FEEDBACK' is disabled.
Jan 29 19:55:07 shafeen-Dell-G15-5515 mariadbd[2008]: 2024-01-29 19:55:07 0 [Warning] You need to use --log-bin to make --expire-logs-days or --binlog-expire-logs-seconds work.
Jan 29 19:55:07 shafeen-Dell-G15-5515 mariadbd[2008]: 2024-01-29 19:55:07 0 [Note] InnoDB: Buffer pool(s) load completed at 240129 19:55:07
Jan 29 19:55:07 shafeen-Dell-G15-5515 mariadbd[2008]: 2024-01-29 19:55:07 0 [Note] Server socket created on IP: '127.0.0.1'.
Jan 29 19:55:07 shafeen-Dell-G15-5515 mariadbd[2008]: 2024-01-29 19:55:07 0 [Note] /usr/sbin/mariadbd: ready for connections.
Jan 29 19:55:07 shafeen-Dell-G15-5515 mariadbd[2008]: Version: '10.11.6-MariaDB-0ubuntu0.23.10.2'  socket: '/run/mysqld/mysqld.sock'  port: 3306  Ubuntu 23.10
Jan 29 19:55:07 shafeen-Dell-G15-5515 systemd[1]: Started mariadb.service - MariaDB 10.11.6 database server.
Jan 29 19:55:07 shafeen-Dell-G15-5515 /etc/mysql/debian-start[2139]: Upgrading MySQL tables if necessary.
Jan 29 19:55:07 shafeen-Dell-G15-5515 /etc/mysql/debian-start[2154]: Triggering myisam-recover for all MyISAM tables and aria-recover for all Aria tables
Jan 30 14:51:46 shafeen-Dell-G15-5515 mariadbd[2008]: 2024-01-30 14:51:46 31 [Warning] Access denied for user 'root'@'localhost'
shafeen@shafeen-Dell-G15-5515 ~ [SIGINT]> sudo /opt/lampp/lampp start

Starting XAMPP for Linux 8.2.12-0...
XAMPP: Starting Apache...ok.
XAMPP: Starting MySQL...ok.
XAMPP: Starting ProFTPD...ok.
shafeen@shafeen-Dell-G15-5515 ~> sudo systemctl status mysql
● mariadb.service - MariaDB 10.11.6 database server
     Loaded: loaded (/lib/systemd/system/mariadb.service; enabled; preset: enabled)
     Active: active (running) since Mon 2024-01-29 19:55:07 PKT; 1 day 3h ago
       Docs: man:mariadbd(8)
             https://mariadb.com/kb/en/library/systemd/
    Process: 1749 ExecStartPre=/usr/bin/install -m 755 -o mysql -g root -d /var/run/mysqld (code=exited, status=0/SUCCESS)
    Process: 1855 ExecStartPre=/bin/sh -c systemctl unset-environment _WSREP_START_POSITION (code=exited, status=0/SUCCESS)
    Process: 1899 ExecStartPre=/bin/sh -c [ ! -e /usr/bin/galera_recovery ] && VAR= ||   VAR=`cd /usr/bin/..; /usr/bin/galera_recovery`; [ $? -eq 0 ]   && systemctl set-environment _WSREP_S>
    Process: 2135 ExecStartPost=/bin/sh -c systemctl unset-environment _WSREP_START_POSITION (code=exited, status=0/SUCCESS)
    Process: 2137 ExecStartPost=/etc/mysql/debian-start (code=exited, status=0/SUCCESS)
   Main PID: 2008 (mariadbd)
     Status: "Taking your SQL requests now..."
      Tasks: 12 (limit: 37641)
     Memory: 112.5M
        CPU: 6.165s
     CGroup: /system.slice/mariadb.service
             └─2008 /usr/sbin/mariadbd

Jan 29 19:55:07 shafeen-Dell-G15-5515 mariadbd[2008]: 2024-01-29 19:55:07 0 [Note] Plugin 'FEEDBACK' is disabled.
Jan 29 19:55:07 shafeen-Dell-G15-5515 mariadbd[2008]: 2024-01-29 19:55:07 0 [Warning] You need to use --log-bin to make --expire-logs-days or --binlog-expire-logs-seconds work.
Jan 29 19:55:07 shafeen-Dell-G15-5515 mariadbd[2008]: 2024-01-29 19:55:07 0 [Note] InnoDB: Buffer pool(s) load completed at 240129 19:55:07
Jan 29 19:55:07 shafeen-Dell-G15-5515 mariadbd[2008]: 2024-01-29 19:55:07 0 [Note] Server socket created on IP: '127.0.0.1'.
Jan 29 19:55:07 shafeen-Dell-G15-5515 mariadbd[2008]: 2024-01-29 19:55:07 0 [Note] /usr/sbin/mariadbd: ready for connections.
Jan 29 19:55:07 shafeen-Dell-G15-5515 mariadbd[2008]: Version: '10.11.6-MariaDB-0ubuntu0.23.10.2'  socket: '/run/mysqld/mysqld.sock'  port: 3306  Ubuntu 23.10
Jan 29 19:55:07 shafeen-Dell-G15-5515 systemd[1]: Started mariadb.service - MariaDB 10.11.6 database server.
Jan 29 19:55:07 shafeen-Dell-G15-5515 /etc/mysql/debian-start[2139]: Upgrading MySQL tables if necessary.
Jan 29 19:55:07 shafeen-Dell-G15-5515 /etc/mysql/debian-start[2154]: Triggering myisam-recover for all MyISAM tables and aria-recover for all Aria tables
Jan 30 14:51:46 shafeen-Dell-G15-5515 mariadbd[2008]: 2024-01-30 14:51:46 31 [Warning] Access denied for user 'root'@'localhost'
...skipping...
● mariadb.service - MariaDB 10.11.6 database server
     Loaded: loaded (/lib/systemd/system/mariadb.service; enabled; preset: enabled)
     Active: active (running) since Mon 2024-01-29 19:55:07 PKT; 1 day 3h ago
       Docs: man:mariadbd(8)
             https://mariadb.com/kb/en/library/systemd/
    Process: 1749 ExecStartPre=/usr/bin/install -m 755 -o mysql -g root -d /var/run/mysqld (code=exited, status=0/SUCCESS)
    Process: 1855 ExecStartPre=/bin/sh -c systemctl unset-environment _WSREP_START_POSITION (code=exited, status=0/SUCCESS)
    Process: 1899 ExecStartPre=/bin/sh -c [ ! -e /usr/bin/galera_recovery ] && VAR= ||   VAR=`cd /usr/bin/..; /usr/bin/galera_recovery`; [ $? -eq 0 ]   && systemctl set-environment _WSREP_S>
    Process: 2135 ExecStartPost=/bin/sh -c systemctl unset-environment _WSREP_START_POSITION (code=exited, status=0/SUCCESS)
    Process: 2137 ExecStartPost=/etc/mysql/debian-start (code=exited, status=0/SUCCESS)
   Main PID: 2008 (mariadbd)
     Status: "Taking your SQL requests now..."
      Tasks: 12 (limit: 37641)
     Memory: 112.5M
        CPU: 6.165s
     CGroup: /system.slice/mariadb.service
             └─2008 /usr/sbin/mariadbd

Jan 29 19:55:07 shafeen-Dell-G15-5515 mariadbd[2008]: 2024-01-29 19:55:07 0 [Note] Plugin 'FEEDBACK' is disabled.
Jan 29 19:55:07 shafeen-Dell-G15-5515 mariadbd[2008]: 2024-01-29 19:55:07 0 [Warning] You need to use --log-bin to make --expire-logs-days or --binlog-expire-logs-seconds work.
Jan 29 19:55:07 shafeen-Dell-G15-5515 mariadbd[2008]: 2024-01-29 19:55:07 0 [Note] InnoDB: Buffer pool(s) load completed at 240129 19:55:07
Jan 29 19:55:07 shafeen-Dell-G15-5515 mariadbd[2008]: 2024-01-29 19:55:07 0 [Note] Server socket created on IP: '127.0.0.1'.
Jan 29 19:55:07 shafeen-Dell-G15-5515 mariadbd[2008]: 2024-01-29 19:55:07 0 [Note] /usr/sbin/mariadbd: ready for connections.
Jan 29 19:55:07 shafeen-Dell-G15-5515 mariadbd[2008]: Version: '10.11.6-MariaDB-0ubuntu0.23.10.2'  socket: '/run/mysqld/mysqld.sock'  port: 3306  Ubuntu 23.10
Jan 29 19:55:07 shafeen-Dell-G15-5515 systemd[1]: Started mariadb.service - MariaDB 10.11.6 database server.
Jan 29 19:55:07 shafeen-Dell-G15-5515 /etc/mysql/debian-start[2139]: Upgrading MySQL tables if necessary.
Jan 29 19:55:07 shafeen-Dell-G15-5515 /etc/mysql/debian-start[2154]: Triggering myisam-recover for all MyISAM tables and aria-recover for all Aria tables
Jan 30 14:51:46 shafeen-Dell-G15-5515 mariadbd[2008]: 2024-01-30 14:51:46 31 [Warning] Access denied for user 'root'@'localhost'
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
shafeen@shafeen-Dell-G15-5515 ~ [SIGINT]> sudo systemctl status mysql
● mariadb.service - MariaDB 10.11.6 database server
     Loaded: loaded (/lib/systemd/system/mariadb.service; enabled; preset: enabled)
     Active: active (running) since Mon 2024-01-29 19:55:07 PKT; 1 day 3h ago
       Docs: man:mariadbd(8)
             https://mariadb.com/kb/en/library/systemd/
    Process: 1749 ExecStartPre=/usr/bin/install -m 755 -o mysql -g root -d /var/run/mysqld (code=exited, status=0/SUCCESS)
    Process: 1855 ExecStartPre=/bin/sh -c systemctl unset-environment _WSREP_START_POSITION (code=exited, status=0/SUCCESS)
    Process: 1899 ExecStartPre=/bin/sh -c [ ! -e /usr/bin/galera_recovery ] && VAR= ||   VAR=`cd /usr/bin/..; /usr/bin/galera_recovery`; [ $? -eq 0 ]   && systemctl set-environment _WSREP_S>
    Process: 2135 ExecStartPost=/bin/sh -c systemctl unset-environment _WSREP_START_POSITION (code=exited, status=0/SUCCESS)
    Process: 2137 ExecStartPost=/etc/mysql/debian-start (code=exited, status=0/SUCCESS)
   Main PID: 2008 (mariadbd)
     Status: "Taking your SQL requests now..."
      Tasks: 12 (limit: 37641)
     Memory: 112.5M
        CPU: 6.167s
     CGroup: /system.slice/mariadb.service
             └─2008 /usr/sbin/mariadbd

Jan 29 19:55:07 shafeen-Dell-G15-5515 mariadbd[2008]: 2024-01-29 19:55:07 0 [Note] Plugin 'FEEDBACK' is disabled.
Jan 29 19:55:07 shafeen-Dell-G15-5515 mariadbd[2008]: 2024-01-29 19:55:07 0 [Warning] You need to use --log-bin to make --expire-logs-days or --binlog-expire-logs-seconds work.
Jan 29 19:55:07 shafeen-Dell-G15-5515 mariadbd[2008]: 2024-01-29 19:55:07 0 [Note] InnoDB: Buffer pool(s) load completed at 240129 19:55:07
Jan 29 19:55:07 shafeen-Dell-G15-5515 mariadbd[2008]: 2024-01-29 19:55:07 0 [Note] Server socket created on IP: '127.0.0.1'.
Jan 29 19:55:07 shafeen-Dell-G15-5515 mariadbd[2008]: 2024-01-29 19:55:07 0 [Note] /usr/sbin/mariadbd: ready for connections.
Jan 29 19:55:07 shafeen-Dell-G15-5515 mariadbd[2008]: Version: '10.11.6-MariaDB-0ubuntu0.23.10.2'  socket: '/run/mysqld/mysqld.sock'  port: 3306  Ubuntu 23.10
Jan 29 19:55:07 shafeen-Dell-G15-5515 systemd[1]: Started mariadb.service - MariaDB 10.11.6 database server.
Jan 29 19:55:07 shafeen-Dell-G15-5515 /etc/mysql/debian-start[2139]: Upgrading MySQL tables if necessary.
Jan 29 19:55:07 shafeen-Dell-G15-5515 /etc/mysql/debian-start[2154]: Triggering myisam-recover for all MyISAM tables and aria-recover for all Aria tables
Jan 30 14:51:46 shafeen-Dell-G15-5515 mariadbd[2008]: 2024-01-30 14:51:46 31 [Warning] Access denied for user 'root'@'localhost'
 ^X⏎                                                                                                                                                                                          shafeen@shafeen-Dell-G15-5515 ~ [SIGINT]> sudo /opt/lampp/lampp status

Version: XAMPP for Linux 8.2.12-0
Apache is running.
MySQL is not running.
ProFTPD is running.
shafeen@shafeen-Dell-G15-5515 ~> sudo tail -n 20 /opt/lampp/var/mysql/{hostname}.err

tail: cannot open '/opt/lampp/var/mysql/{hostname}.err' for reading: No such file or directory
shafeen@shafeen-Dell-G15-5515 ~ [1]> sudo tail -n 20 /opt/lampp/var/mysql/{localhost}.err

tail: cannot open '/opt/lampp/var/mysql/{localhost}.err' for reading: No such file or directory
shafeen@shafeen-Dell-G15-5515 ~ [1]> sudo tail -n 20 /opt/lampp/var/mysql/{localhos}.err
                                     ^C
shafeen@shafeen-Dell-G15-5515 ~ [1]> sudo /opt/lampp/lampp startmysql

XAMPP: Starting MySQL...ok.
shafeen@shafeen-Dell-G15-5515 ~> sudo /opt/lampp/lampp status

Version: XAMPP for Linux 8.2.12-0
Apache is running.
MySQL is not running.
ProFTPD is running.
shafeen@shafeen-Dell-G15-5515 ~> sudo lsof -i :3306

COMMAND   PID  USER   FD   TYPE DEVICE SIZE/OFF NODE NAME
mariadbd 2008 mysql   21u  IPv4   1024      0t0  TCP localhost:mysql (LISTEN)
shafeen@shafeen-Dell-G15-5515 ~> sudo /opt/lampp/lampp stop
                                 sudo /opt/lampp/lampp start

Stopping XAMPP for Linux 8.2.12-0...
XAMPP: Stopping Apache...ok.
XAMPP: Stopping MySQL...not running.
XAMPP: Stopping ProFTPD...ok.
Starting XAMPP for Linux 8.2.12-0...
XAMPP: Starting Apache...ok.
XAMPP: Starting MySQL...ok.
XAMPP: Starting ProFTPD...ok.
shafeen@shafeen-Dell-G15-5515 ~> sudo /opt/lampp/lampp status

Version: XAMPP for Linux 8.2.12-0
Apache is running.
MySQL is not running.
ProFTPD is running.
shafeen@shafeen-Dell-G15-5515 ~> sudo /opt/lampp/lampp stop
                                 sudo /opt/lampp/lampp start

Stopping XAMPP for Linux 8.2.12-0...
XAMPP: Stopping Apache...ok.
XAMPP: Stopping MySQL...not running.
XAMPP: Stopping ProFTPD...ok.
Starting XAMPP for Linux 8.2.12-0...
XAMPP: Starting Apache...ok.
XAMPP: Starting MySQL...ok.
XAMPP: Starting ProFTPD...ok.
shafeen@shafeen-Dell-G15-5515 ~> sudo nano /opt/lampp/etc/my.cnf

shafeen@shafeen-Dell-G15-5515 ~> sudo lsof -i :3306

COMMAND   PID  USER   FD   TYPE DEVICE SIZE/OFF NODE NAME
mariadbd 2008 mysql   21u  IPv4   1024      0t0  TCP localhost:mysql (LISTEN)
shafeen@shafeen-Dell-G15-5515 ~> sudo service mariadb stop

shafeen@shafeen-Dell-G15-5515 ~> sudo /opt/lampp/lampp startmysql

XAMPP: Starting MySQL...ok.
shafeen@shafeen-Dell-G15-5515 ~> sudo nano /opt/lampp/etc/my.cnf

shafeen@shafeen-Dell-G15-5515 ~> sudo /opt/lampp/lampp restartmysql

Unknown command or add-on!
shafeen@shafeen-Dell-G15-5515 ~> sudo /opt/lampp/ restartmysql

sudo: /opt/lampp/: command not found
shafeen@shafeen-Dell-G15-5515 ~ [1]> sudo /opt/lampp/ restart mysql

sudo: /opt/lampp/: command not found
shafeen@shafeen-Dell-G15-5515 ~ [1]> sudo /opt/lampp/ restart mysql
                                      ^C
shafeen@shafeen-Dell-G15-5515 ~ [1]> sudo /opt/lampp/lampp restartmysql
                                     ^C
shafeen@shafeen-Dell-G15-5515 ~ [1]> fish
Welcome to fish, the friendly interactive shell
Type help for instructions on how to use fish
shafeen@shafeen-Dell-G15-5515 ~> sudo /opt/lampp/lampp stop
                                 sudo /opt/lampp/lampp start

Stopping XAMPP for Linux 8.2.12-0...
XAMPP: Stopping Apache...ok.
XAMPP: Stopping MySQL...ok.
XAMPP: Stopping ProFTPD...ok.
Starting XAMPP for Linux 8.2.12-0...
XAMPP: Starting Apache...ok.
XAMPP: Starting MySQL...ok.
XAMPP: Starting ProFTPD...ok.
shafeen@shafeen-Dell-G15-5515 ~> sudo /opt/lampp/lampp status

Version: XAMPP for Linux 8.2.12-0
Apache is running.
MySQL is running.
ProFTPD is running.
shafeen@shafeen-Dell-G15-5515 ~> sudo /opt/lampp/bin/mysqldump -u root -p THEME_PARK > /home/shafeen/Desktop/newthemepark.sql
Enter password: 
mysqldump: Got error: 1049: "Unknown database 'THEME_PARK'" when selecting the database
shafeen@shafeen-Dell-G15-5515 ~ [2]> mysql -u root -p
Enter password: 
ERROR 2002 (HY000): Can't connect to local server through socket '/run/mysqld/mysqld.sock' (2)
shafeen@shafeen-Dell-G15-5515 ~ [1]> sudo /opt/lampp/bin/mysqldump -u root -p THEME_PARK > /home/shafeen/Desktop/newthemepark.sql
Enter password: 
mysqldump: Got error: 1049: "Unknown database 'THEME_PARK'" when selecting the database
shafeen@shafeen-Dell-G15-5515 ~ [2]> sudo /opt/lampp/bin/mysql -u root -p -e "SHOW DATABASES;"

Enter password: 
+--------------------+
| Database           |
+--------------------+
| information_schema |
| mysql              |
| performance_schema |
| phpmyadmin         |
| test               |
+--------------------+
shafeen@shafeen-Dell-G15-5515 ~> sudo /opt/lampp/bin/mysql -u root -p
Enter password: 
Welcome to the MariaDB monitor.  Commands end with ; or \g.
Your MariaDB connection id is 12
Server version: 10.4.32-MariaDB Source distribution

Copyright (c) 2000, 2018, Oracle, MariaDB Corporation Ab and others.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

MariaDB [(none)]> SHOW databases;
+--------------------+
| Database           |
+--------------------+
| information_schema |
| mysql              |
| performance_schema |
| phpmyadmin         |
| test               |
+--------------------+
5 rows in set (0.000 sec)

MariaDB [(none)]> exit
Bye
shafeen@shafeen-Dell-G15-5515 ~> sudo mysql -u root
ERROR 2002 (HY000): Can't connect to local server through socket '/run/mysqld/mysqld.sock' (2)
shafeen@shafeen-Dell-G15-5515 ~ [1]> sudo mysql -u root
ERROR 2002 (HY000): Can't connect to local server through socket '/run/mysqld/mysqld.sock' (2)
shafeen@shafeen-Dell-G15-5515 ~ [1]> sudo mysql -u root
ERROR 2002 (HY000): Can't connect to local server through socket '/run/mysqld/mysqld.sock' (2)
shafeen@shafeen-Dell-G15-5515 ~ [1]> sudo /opt/lampp/bin/mysql -u root -p
Enter password: 
Welcome to the MariaDB monitor.  Commands end with ; or \g.
Your MariaDB connection id is 13
Server version: 10.4.32-MariaDB Source distribution

Copyright (c) 2000, 2018, Oracle, MariaDB Corporation Ab and others.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

MariaDB [(none)]> Ctrl-C -- exit!
Aborted
shafeen@shafeen-Dell-G15-5515 ~ [1]> sudo mysql -u root
ERROR 2002 (HY000): Can't connect to local server through socket '/run/mysqld/mysqld.sock' (2)
shafeen@shafeen-Dell-G15-5515 ~ [1]> sudo /opt/lampp/bin/mysql -u root -p
Enter password: 
Welcome to the MariaDB monitor.  Commands end with ; or \g.
Your MariaDB connection id is 14
Server version: 10.4.32-MariaDB Source distribution

Copyright (c) 2000, 2018, Oracle, MariaDB Corporation Ab and others.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

MariaDB [(none)]> Ctrl-C -- exit!
Aborted
shafeen@shafeen-Dell-G15-5515 ~ [1]> sudo /opt/lampp/bin/mysql -u root -p -e "SHOW DATABASES;"
                                     ^C
shafeen@shafeen-Dell-G15-5515 ~ [1]> sudo ^C
shafeen@shafeen-Dell-G15-5515 ~ [1]> sudo nano /opt/lampp/etc/my.cnf

shafeen@shafeen-Dell-G15-5515 ~> sudo nano /opt/lampp/etc/my.cnf

shafeen@shafeen-Dell-G15-5515 ~> sudo /opt/lampp/bin/mysql -u root -p
Enter password: 
Welcome to the MariaDB monitor.  Commands end with ; or \g.
Your MariaDB connection id is 15
Server version: 10.4.32-MariaDB Source distribution

Copyright (c) 2000, 2018, Oracle, MariaDB Corporation Ab and others.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

MariaDB [(none)]> SHOW databases;
+--------------------+
| Database           |
+--------------------+
| information_schema |
| mysql              |
| performance_schema |
| phpmyadmin         |
| test               |
+--------------------+
5 rows in set (0.000 sec)

MariaDB [(none)]> USE mysql
Reading table information for completion of table and column names
You can turn off this feature to get a quicker startup with -A

Database changed
MariaDB [mysql]> create database Theme_park;
Query OK, 1 row affected (0.000 sec)

MariaDB [mysql]> show databases;
+--------------------+
| Database           |
+--------------------+
| Theme_park         |
| information_schema |
| mysql              |
| performance_schema |
| phpmyadmin         |
| test               |
+--------------------+
6 rows in set (0.000 sec)

MariaDB [mysql]> USE theme_park
ERROR 1049 (42000): Unknown database 'theme_park'
MariaDB [mysql]> USE DATABASE Theme_park
ERROR 1049 (42000): Unknown database 'DATABASE'
MariaDB [mysql]> USE Theme_park
Database changed
MariaDB [Theme_park]> CREATE TABLE THEMEPARK (
    -> PARK_CODE VARCHAR(10) PRIMARY KEY,
    -> PARK_NAME VARCHAR(35) NOT NULL,
    -> PARK_CITY VARCHAR(50) NOT NULL,
    -> PARK_COUNTRY CHAR(2) NOT NULL);
Query OK, 0 rows affected (0.011 sec)

MariaDB [Theme_park]> show tables
    -> ;
+----------------------+
| Tables_in_Theme_park |
+----------------------+
| THEMEPARK            |
+----------------------+
1 row in set (0.000 sec)

MariaDB [Theme_park]> CREATE TABLE EMPLOYEE(
    -> EMP_NUM NUMERIC(4) PRIMARY KEY,
    -> EMP_TITLE VARCHAR(4),
    -> EMP_LNAME VARCHAR(15) NOT NULL,
    -> EMP_FNAME VARCHAR(15) NOT NULL,
    -> EMP_DOB DATE NOT NULL,
    -> EMP_HIRE_DATE DATE,
    -> EMP_AREA_CODE VARCHAR(4) NOT NULL,
    -> EMP_PHONE VARCHAR(12)NOT NULL,
    -> PARK_CODE VARCHAR(10),
    -> INDEX (PARK_CODE),
    -> CONSTRAINT FK_EMP_PARK FOREIGN KEY(PARK_CODE) REFERENCES THEMEPARK(PARK_CODE));
Query OK, 0 rows affected (0.015 sec)

MariaDB [Theme_park]> CREATE TABLE TICKET (
    -> TICKET_NO NUMERIC(10) PRIMARY KEY,
    -> TICKET_PRICE VARCHAR(10),
    -> PARK_CODE VARCHAR(10),
    -> INDEX (PARK_CODE),
    -> CONSTRAINT FK_TICKET_PARK FOREIGN KEY(PARK_CODE) REFERENCES THEMEPARK(PARK_CODE));
Query OK, 0 rows affected (0.013 sec)

MariaDB [Theme_park]> CREATE TABLE ATTRACTION (
    -> ATTRACT_NO NUMERIC(10) PRIMARY KEY,
    -> ATTRACT_NAME VARCHAR(35),
    -> ATTRACT_AGE NUMERIC(3) DEFAULT 0 NOT NULL,
    -> ATTRACT_CAPACITY NUMERIC(3) NOT NULL,
    -> PARK_CODE VARCHAR(10),
    -> INDEX (PARK_CODE),
    -> CONSTRAINT FK_ATTRACT_PARK FOREIGN KEY(PARK_CODE) REFERENCES THEMEPARK(PARK_CODE));
Query OK, 0 rows affected (0.014 sec)

MariaDB [Theme_park]> CREATE TABLE HOURS (
    -> EMP_NUM NUMERIC(4),
    -> ATTRACT_NO NUMERIC(10),
    -> HOURS_PER_ATTRACT NUMERIC(2) NOT NULL,
    -> HOUR_RATE NUMERIC(4,2) NOT NULL,
    -> DATE_WORKED DATE NOT NULL,
    -> INDEX (EMP_NUM),
    -> INDEX (ATTRACT_NO),
    -> CONSTRAINT PK_HOURS PRIMARY KEY (EMP_NUM, ATTRACT_NO, DATE_WORKED),
    -> CONSTRAINT FK_HOURS_EMP FOREIGN KEY (EMP_NUM) REFERENCES EMPLOYEE(EMP_NUM),
    -> CONSTRAINT FK_HOURS_ATTRACT FOREIGN KEY (ATTRACT_NO) REFERENCES ATTRACTION(ATTRACT_NO));
Query OK, 0 rows affected, 1 warning (0.017 sec)

MariaDB [Theme_park]> CREATE TABLE SALES (
    -> TRANSACTION_NO NUMERIC PRIMARY KEY,
    -> PARK_CODE VARCHAR(10),
    -> SALE_DATE DATE NOT NULL,
    -> INDEX (PARK_CODE),
    -> CONSTRAINT FK_SALES_PARK FOREIGN KEY(PARK_CODE) REFERENCES THEMEPARK(PARK_CODE));
Query OK, 0 rows affected (0.013 sec)

MariaDB [Theme_park]> CREATE TABLE SALES_LINE (
    -> TRANSACTION_NO NUMERIC,
    -> LINE_NO NUMERIC(2,0) NOT NULL,
    -> TICKET_NO NUMERIC(10) NOT NULL,
    -> LINE_QTY NUMERIC(4) DEFAULT 0 NOT NULL,
    -> LINE_PRICE NUMERIC(9,2) DEFAULT 0.00 NOT NULL,
    -> INDEX (TRANSACTION_NO),
    -> INDEX (TICKET_NO),
    -> CONSTRAINT PK_SALES_LINE PRIMARY KEY (TRANSACTION_NO, LINE_NO),
    -> CONSTRAINT FK_SALES_LINE_SALES FOREIGN KEY (TRANSACTION_NO) REFERENCES SALES(TRANSACTION_NO),
    -> CONSTRAINT FK_SALES_LINE_TICKET FOREIGN KEY (TICKET_NO) REFERENCES TICKET(TICKET_NO));
Query OK, 0 rows affected, 1 warning (0.017 sec)

MariaDB [Theme_park]> show databases;
+--------------------+
| Database           |
+--------------------+
| Theme_park         |
| information_schema |
| mysql              |
| performance_schema |
| phpmyadmin         |
| test               |
+--------------------+
6 rows in set (0.000 sec)

MariaDB [Theme_park]> show tables;
+----------------------+
| Tables_in_Theme_park |
+----------------------+
| ATTRACTION           |
| EMPLOYEE             |
| HOURS                |
| SALES                |
| SALES_LINE           |
| THEMEPARK            |
| TICKET               |
+----------------------+
7 rows in set (0.000 sec)

MariaDB [Theme_park]> exit
Bye
shafeen@shafeen-Dell-G15-5515 ~> sudo /opt/lampp/bin/mysql -u root -p
[sudo] password for shafeen: 
PapigfSorry, try again.
[sudo] password for shafeen: 
Sorry, try again.
[sudo] password for shafeen: 
sudo: 3 incorrect password attempts
shafeen@shafeen-Dell-G15-5515 ~ [1]> sudo /opt/lampp/bin/mysql -u root -p
[sudo] password for shafeen: 
Enter password: 
Welcome to the MariaDB monitor.  Commands end with ; or \g.
Your MariaDB connection id is 16
Server version: 10.4.32-MariaDB Source distribution

Copyright (c) 2000, 2018, Oracle, MariaDB Corporation Ab and others.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

MariaDB [(none)]> show databases;
+--------------------+
| Database           |
+--------------------+
| Theme_park         |
| information_schema |
| mysql              |
| performance_schema |
| phpmyadmin         |
| test               |
+--------------------+
6 rows in set (0.000 sec)

MariaDB [(none)]> USE Theme_park;
Reading table information for completion of table and column names
You can turn off this feature to get a quicker startup with -A

Database changed
MariaDB [Theme_park]> show tables;
+----------------------+
| Tables_in_Theme_park |
+----------------------+
| ATTRACTION           |
| EMPLOYEE             |
| HOURS                |
| SALES                |
| SALES_LINE           |
| THEMEPARK            |
| TICKET               |
+----------------------+
7 rows in set (0.000 sec)

MariaDB [Theme_park]> exit
Bye
shafeen@shafeen-Dell-G15-5515 ~> sudo /opt/lampp/bin/mysqldumb
sudo: /opt/lampp/bin/mysqldumb: command not found
shafeen@shafeen-Dell-G15-5515 ~ [1]> sudo /opt/lampp/bin/mysqldump -u root -p Theme_park > /home/shafeen/Desktop/newthemqepark.sql
Enter password: 
shafeen@shafeen-Dell-G15-5515 ~> sudo /opt/lampp/bin/mysql -u root -p
Enter password: 
Welcome to the MariaDB monitor.  Commands end with ; or \g.
Your MariaDB connection id is 18
Server version: 10.4.32-MariaDB Source distribution

Copyright (c) 2000, 2018, Oracle, MariaDB Corporation Ab and others.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

MariaDB [(none)]> use Theme_park;
Reading table information for completion of table and column names
You can turn off this feature to get a quicker startup with -A

Database changed
MariaDB [Theme_park]> DROP TABLE SALES_LINE;
Query OK, 0 rows affected (0.007 sec)

MariaDB [Theme_park]> DROP TABLE SALES;
Query OK, 0 rows affected (0.008 sec)

MariaDB [Theme_park]> DROP TABLE HOURS;
Query OK, 0 rows affected (0.011 sec)

MariaDB [Theme_park]> DROP TABLE ATTRACTION;
Query OK, 0 rows affected (0.007 sec)

MariaDB [Theme_park]> DROP TABLE TICKET;
Query OK, 0 rows affected (0.006 sec)

MariaDB [Theme_park]> DROP TABLE EMPLOYEE;
Query OK, 0 rows affected (0.007 sec)

MariaDB [Theme_park]> show tables;
+----------------------+
| Tables_in_Theme_park |
+----------------------+
| THEMEPARK            |
+----------------------+
1 row in set (0.000 sec)

MariaDB [Theme_park]> DROP THEMEPARL
    -> ;~
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'THEMEPARL' at line 1
    -> DROP THEMEPARK
    -> ;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near '~
DROP THEMEPARK' at line 1
MariaDB [Theme_park]> DROP THEMEPARK
    -> ;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'THEMEPARK' at line 1
MariaDB [Theme_park]> SHOW TABLES;
+----------------------+
| Tables_in_Theme_park |
+----------------------+
| THEMEPARK            |
+----------------------+
1 row in set (0.000 sec)

MariaDB [Theme_park]> DROP THEMEPARK
    -> ;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'THEMEPARK' at line 1
MariaDB [Theme_park]> DROP TABLE THEMEPARK;
Query OK, 0 rows affected (0.010 sec)

MariaDB [Theme_park]> show tables
    -> ;
Empty set (0.000 sec)

MariaDB [Theme_park]> themepark.sql script
    -> ;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'themepark.sql script' at line 1
MariaDB [Theme_park]> themepark.sql
    -> ;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'themepark.sql' at line 1
MariaDB [Theme_park]> source /home/shafeen/Desktop/newthemepark.sql
ERROR: Failed to open file '/home/shafeen/Desktop/newthemepark.sql', error: 2
MariaDB [Theme_park]> source /home/shafeen/Desktop/newthemepark.sql
ERROR: Failed to open file '/home/shafeen/Desktop/newthemepark.sql', error: 2
MariaDB [Theme_park]> show databasesl
    -> 
    -> show databases;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'databasesl

show databases' at line 3
MariaDB [Theme_park]> show DATABASES;
+--------------------+
| Database           |
+--------------------+
| Theme_park         |
| information_schema |
| mysql              |
| performance_schema |
| phpmyadmin         |
| test               |
+--------------------+
6 rows in set (0.000 sec)

MariaDB [Theme_park]> /home/shafeen/Desktop
    -> ;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near '/home/shafeen/Desktop' at line 1
MariaDB [Theme_park]> source /home/shafeen/Desktop/newthemqpark.sql
ERROR: Failed to open file '/home/shafeen/Desktop/newthemqpark.sql', error: 2
MariaDB [Theme_park]> source /home/shafeen/Desktop/newthemqepark.sql
Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

ERROR 1051 (42S02) at line 21 in file: '/home/shafeen/Desktop/newthemqepark.sql': Unknown table 'Theme_park.SALES_LINE'
ERROR 1051 (42S02) at line 22 in file: '/home/shafeen/Desktop/newthemqepark.sql': Unknown table 'Theme_park.SALES'
ERROR 1051 (42S02) at line 23 in file: '/home/shafeen/Desktop/newthemqepark.sql': Unknown table 'Theme_park.HOURS'
ERROR 1051 (42S02) at line 24 in file: '/home/shafeen/Desktop/newthemqepark.sql': Unknown table 'Theme_park.ATTRACTION'
ERROR 1051 (42S02) at line 25 in file: '/home/shafeen/Desktop/newthemqepark.sql': Unknown table 'Theme_park.TICKET'
ERROR 1051 (42S02) at line 26 in file: '/home/shafeen/Desktop/newthemqepark.sql': Unknown table 'Theme_park.EMPLOYEE'
ERROR 1051 (42S02) at line 27 in file: '/home/shafeen/Desktop/newthemqepark.sql': Unknown table 'Theme_park.THEMEPARK'
Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.015 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.013 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.016 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.001 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.016 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.001 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.017 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.010 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.001 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.014 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.001 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

MariaDB [Theme_park]> show tables;
+----------------------+
| Tables_in_Theme_park |
+----------------------+
| ATTRACTION           |
| EMPLOYEE             |
| HOURS                |
| SALES                |
| SALES_LINE           |
| THEMEPARK            |
| TICKET               |
+----------------------+
7 rows in set (0.000 sec)

MariaDB [Theme_park]> describe ATTRACTION
    -> ;
+------------------+---------------+------+-----+---------+-------+
| Field            | Type          | Null | Key | Default | Extra |
+------------------+---------------+------+-----+---------+-------+
| ATTRACT_NO       | decimal(10,0) | NO   | PRI | NULL    |       |
| ATTRACT_NAME     | varchar(35)   | YES  |     | NULL    |       |
| ATTRACT_AGE      | decimal(3,0)  | NO   |     | 0       |       |
| ATTRACT_CAPACITY | decimal(3,0)  | NO   |     | NULL    |       |
| PARK_CODE        | varchar(10)   | YES  | MUL | NULL    |       |
+------------------+---------------+------+-----+---------+-------+
5 rows in set (0.001 sec)

MariaDB [Theme_park]> SHOW TABLES;
+----------------------+
| Tables_in_Theme_park |
+----------------------+
| ATTRACTION           |
| EMPLOYEE             |
| HOURS                |
| SALES                |
| SALES_LINE           |
| THEMEPARK            |
| TICKET               |
+----------------------+
7 rows in set (0.000 sec)

MariaDB [Theme_park]> INSERT INTO THEMEPARK VALUES ('FR1001','FairyLand','PARIS','FR');
Query OK, 1 row affected (0.004 sec)

MariaDB [Theme_park]> INSERT INTO THEMEPARK VALUES ('UK3452','PleasureLand','STOKE','UK');
Query OK, 1 row affected (0.004 sec)

MariaDB [Theme_park]> INSERT INTO TICKET VALUES (13001,18.99,'Child','FR1001');
ERROR 1136 (21S01): Column count doesn't match value count at row 1
MariaDB [Theme_park]> INSERT INTO TICKET VALUES (13002,34.99,'Adult','FR1001');
ERROR 1136 (21S01): Column count doesn't match value count at row 1
MariaDB [Theme_park]> INSERT INTO TICKET VALUES (13003,20.99,'Senior','FR1001');
ERROR 1136 (21S01): Column count doesn't match value count at row 1
MariaDB [Theme_park]> INSERT INTO TICKET VALUES (88567,22.50,'Child','UK3452');
ERROR 1136 (21S01): Column count doesn't match value count at row 1
MariaDB [Theme_park]> INSERT INTO TICKET VALUES (88568,42.10,'Adult','UK3452');INSERT INTO TICKET VALUES (89720,10.99,'Senior','UK3452');
ERROR 1136 (21S01): Column count doesn't match value count at row 1
ERROR 1136 (21S01): Column count doesn't match value count at row 1
MariaDB [Theme_park]> INSERT INTO TICKET VALUES (13001,18.99,'Child','FR1001');
ERROR 1136 (21S01): Column count doesn't match value count at row 1
MariaDB [Theme_park]> INSERT INTO TICKET VALUES (13001,18.99,'Child','FR1001');
ERROR 1136 (21S01): Column count doesn't match value count at row 1
MariaDB [Theme_park]> INSERT INTO TICKET VALUES (13002,34.99,'Adult','FR1001');
ERROR 1136 (21S01): Column count doesn't match value count at row 1
MariaDB [Theme_park]> INSERT INTO TICKET VALUES (13003,20.99,'Senior','FR1001');
ERROR 1136 (21S01): Column count doesn't match value count at row 1
MariaDB [Theme_park]> TICKET
    -> ;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'TICKET' at line 1
MariaDB [Theme_park]> USE TICKET
ERROR 1049 (42000): Unknown database 'TICKET'
MariaDB [Theme_park]> SHOW TABLE TICKET;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'TICKET' at line 1
MariaDB [Theme_park]> TABLE TICKET;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'TABLE TICKET' at line 1
MariaDB [Theme_park]> describe ticket;
ERROR 1146 (42S02): Table 'Theme_park.ticket' doesn't exist
MariaDB [Theme_park]> DESCRIBE TICKET;
+--------------+---------------+------+-----+---------+-------+
| Field        | Type          | Null | Key | Default | Extra |
+--------------+---------------+------+-----+---------+-------+
| TICKET_NO    | decimal(10,0) | NO   | PRI | NULL    |       |
| TICKET_PRICE | varchar(10)   | YES  |     | NULL    |       |
| PARK_CODE    | varchar(10)   | YES  | MUL | NULL    |       |
+--------------+---------------+------+-----+---------+-------+
3 rows in set (0.001 sec)

MariaDB [Theme_park]> INSERT INTO TICKET VALUES (13001,'Child','FR1001');
Query OK, 1 row affected (0.003 sec)

MariaDB [Theme_park]> SELECT * FROM Theme_park;
ERROR 1146 (42S02): Table 'Theme_park.Theme_park' doesn't exist
MariaDB [Theme_park]> SELECT *
    -> FROM Theme_park;
ERROR 1146 (42S02): Table 'Theme_park.Theme_park' doesn't exist
MariaDB [Theme_park]> SELECT * FROM TICKET;
+-----------+--------------+-----------+
| TICKET_NO | TICKET_PRICE | PARK_CODE |
+-----------+--------------+-----------+
|     13001 | Child        | FR1001    |
+-----------+--------------+-----------+
1 row in set (0.000 sec)

MariaDB [Theme_park]> drop VALUE ('13001')
    -> ;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'VALUE ('13001')' at line 1
MariaDB [Theme_park]> UPDATE TICKET
    -> SET Ctrl-C -- exit!
Aborted
shafeen@shafeen-Dell-G15-5515 ~ [1]> sudo /opt/lampp/bin/mysql -u root -p
Enter password: 
Welcome to the MariaDB monitor.  Commands end with ; or \g.
Your MariaDB connection id is 19
Server version: 10.4.32-MariaDB Source distribution

Copyright (c) 2000, 2018, Oracle, MariaDB Corporation Ab and others.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

MariaDB [(none)]> USE Theme_park;
Reading table information for completion of table and column names
You can turn off this feature to get a quicker startup with -A

Database changed
MariaDB [Theme_park]> show databses;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'databses' at line 1
MariaDB [Theme_park]> show databases;
+--------------------+
| Database           |
+--------------------+
| Theme_park         |
| information_schema |
| mysql              |
| performance_schema |
| phpmyadmin         |
| test               |
+--------------------+
6 rows in set (0.000 sec)

MariaDB [Theme_park]> Show tables;
+----------------------+
| Tables_in_Theme_park |
+----------------------+
| ATTRACTION           |
| EMPLOYEE             |
| HOURS                |
| SALES                |
| SALES_LINE           |
| THEMEPARK            |
| TICKET               |
+----------------------+
7 rows in set (0.000 sec)

MariaDB [Theme_park]> describe ticket
    -> ;
ERROR 1146 (42S02): Table 'Theme_park.ticket' doesn't exist
MariaDB [Theme_park]> DESCRIBE TICKET;
+--------------+---------------+------+-----+---------+-------+
| Field        | Type          | Null | Key | Default | Extra |
+--------------+---------------+------+-----+---------+-------+
| TICKET_NO    | decimal(10,0) | NO   | PRI | NULL    |       |
| TICKET_PRICE | varchar(10)   | YES  |     | NULL    |       |
| PARK_CODE    | varchar(10)   | YES  | MUL | NULL    |       |
+--------------+---------------+------+-----+---------+-------+
3 rows in set (0.001 sec)

MariaDB [Theme_park]> INSERT INTO TICKET VALUES (13001,18.99,'Child','FR1001');
ERROR 1136 (21S01): Column count doesn't match value count at row 1
MariaDB [Theme_park]> INSERT INTO TICKET VALUES (13001,18.99INSERT INTO TICKET VALUES (13001,18.99,'FR1001');,'Child','FR1001');
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'INSERT INTO TICKET VALUES (13001,18.99,'FR1001')' at line 1
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near ''Child','FR1001')' at line 1
MariaDB [Theme_park]> INSERT INTO TICKET VALUES (13002,34.99,'FR1001');
Query OK, 1 row affected (0.003 sec)

MariaDB [Theme_park]> INSERT INTO TICKET VALUES (13003,20.99,'FR1001');
Query OK, 1 row affected (0.005 sec)

MariaDB [Theme_park]> INSERT INTO TICKET VALUES (88567,22.50,'UK3452');
Query OK, 1 row affected (0.002 sec)

MariaDB [Theme_park]> INSERT INTO TICKET VALUES (88568,42.10,'UK3452');
Query OK, 1 row affected (0.002 sec)

MariaDB [Theme_park]> INSERT INTO TICKET VALUES (89720,10.99,'UK3452');
Query OK, 1 row affected (0.003 sec)

MariaDB [Theme_park]> source /opt/lampp/shafeen/Desktop/newthemepark.sql
ERROR: Failed to open file '/opt/lampp/shafeen/Desktop/newthemepark.sql', error: 2
MariaDB [Theme_park]> source INSERT INTO TICKET VALUES (13001,18.99,'FR1001');
ERROR: Failed to open file 'INSERT INTO TICKET VALUES (13001,18.99,'FR1001')', error: 2
MariaDB [Theme_park]> INSERT INTO TICKET VALUES (13002,34.99,'FR1001');
ERROR 1062 (23000): Duplicate entry '13002' for key 'PRIMARY'
MariaDB [Theme_park]> INSERT INTO TICKET VALUES (13003,20.99,'FR1001');
ERROR 1062 (23000): Duplicate entry '13003' for key 'PRIMARY'
MariaDB [Theme_park]> INSERT INTO TICKET VALUES (88567,22.50,'UK3452');
ERROR 1062 (23000): Duplicate entry '88567' for key 'PRIMARY'
MariaDB [Theme_park]> INSERT INTO TICKET VALUES (88568,42.10,'UK3452');
ERROR 1062 (23000): Duplicate entry '88568' for key 'PRIMARY'
MariaDB [Theme_park]> INSERT INTO TICKET VALUES (89720,10.99,'UK3452');Ctrl-C -- exit!
Aborted
shafeen@shafeen-Dell-G15-5515 ~ [1]> sudo /opt/lampp/bin/mysql -u root -p
Enter password: 
Welcome to the MariaDB monitor.  Commands end with ; or \g.
Your MariaDB connection id is 20
Server version: 10.4.32-MariaDB Source distribution

Copyright (c) 2000, 2018, Oracle, MariaDB Corporation Ab and others.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

MariaDB [(none)]> USE Theme_Park;
ERROR 1049 (42000): Unknown database 'Theme_Park'
MariaDB [(none)]> USE Theme_park;
Reading table information for completion of table and column names
You can turn off this feature to get a quicker startup with -A

Database changed
MariaDB [Theme_park]> source /home/shafeen/Desktop/newthemepark.sql
ERROR: Failed to open file '/home/shafeen/Desktop/newthemepark.sql', error: 2
MariaDB [Theme_park]> source /home/shafeen/Desktop/newthemqepark.sql
Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.008 sec)

Query OK, 0 rows affected (0.007 sec)

Query OK, 0 rows affected (0.009 sec)

Query OK, 0 rows affected (0.007 sec)

Query OK, 0 rows affected (0.007 sec)

Query OK, 0 rows affected (0.008 sec)

Query OK, 0 rows affected (0.006 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.014 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.001 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.014 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.016 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.015 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.016 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.011 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.015 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

MariaDB [Theme_park]> SELECT * FROM THEMEPARK;
Empty set (0.001 sec)

MariaDB [Theme_park]> show databases;
+--------------------+
| Database           |
+--------------------+
| Theme_park         |
| information_schema |
| mysql              |
| performance_schema |
| phpmyadmin         |
| test               |
+--------------------+
6 rows in set (0.000 sec)

MariaDB [Theme_park]> SELECT * FROM Theme_park;
ERROR 1146 (42S02): Table 'Theme_park.Theme_park' doesn't exist
MariaDB [Theme_park]> SELECT * FROM TICKET;
Empty set (0.001 sec)

MariaDB [Theme_park]> show tables
    -> ;
+----------------------+
| Tables_in_Theme_park |
+----------------------+
| ATTRACTION           |
| EMPLOYEE             |
| HOURS                |
| SALES                |
| SALES_LINE           |
| THEMEPARK            |
| TICKET               |
+----------------------+
7 rows in set (0.000 sec)

MariaDB [Theme_park]> SELECT * FROM ATTRACTION;
Empty set (0.000 sec)

MariaDB [Theme_park]> SELECT * FROM TICKET;
Empty set (0.000 sec)

MariaDB [Theme_park]> INSERT INTO TICKET VALUES (13001,18.99,'FR1001');
ERROR 1452 (23000): Cannot add or update a child row: a foreign key constraint fails (`Theme_park`.`TICKET`, CONSTRAINT `FK_TICKET_PARK` FOREIGN KEY (`PARK_CODE`) REFERENCES `THEMEPARK` (`PARK_CODE`))
MariaDB [Theme_park]> INSERT INTO TICKET VALUES (13002,34.99,'FR1001');
ERROR 1452 (23000): Cannot add or update a child row: a foreign key constraint fails (`Theme_park`.`TICKET`, CONSTRAINT `FK_TICKET_PARK` FOREIGN KEY (`PARK_CODE`) REFERENCES `THEMEPARK` (`PARK_CODE`))
MariaDB [Theme_park]> INSERT INTO TICKET VALUES (13003,20.99,'FR1001');
ERROR 1452 (23000): Cannot add or update a child row: a foreign key constraint fails (`Theme_park`.`TICKET`, CONSTRAINT `FK_TICKET_PARK` FOREIGN KEY (`PARK_CODE`) REFERENCES `THEMEPARK` (`PARK_CODE`))
MariaDB [Theme_park]> INSERT INTO TICKET VALUES (88567,22.50,'UK3452');
ERROR 1452 (23000): Cannot add or update a child row: a foreign key constraint fails (`Theme_park`.`TICKET`, CONSTRAINT `FK_TICKET_PARK` FOREIGN KEY (`PARK_CODE`) REFERENCES `THEMEPARK` (`PARK_CODE`))
MariaDB [Theme_park]> INSERT INTO TICKET VALUES (88568,42.10,'UK3452');
ERROR 1452 (23000): Cannot add or update a child row: a foreign key constraint fails (`Theme_park`.`TICKET`, CONSTRAINT `FK_TICKET_PARK` FOREIGN KEY (`PARK_CODE`) REFERENCES `THEMEPARK` (`PARK_CODE`))
MariaDB [Theme_park]> INSERT INTO TICKET VALUES (89720,10.99,'UK3452');
ERROR 1452 (23000): Cannot add or update a child row: a foreign key constraint fails (`Theme_park`.`TICKET`, CONSTRAINT `FK_TICKET_PARK` FOREIGN KEY (`PARK_CODE`) REFERENCES `THEMEPARK` (`PARK_CODE`))
MariaDB [Theme_park]> describe TICKET;
+--------------+---------------+------+-----+---------+-------+
| Field        | Type          | Null | Key | Default | Extra |
+--------------+---------------+------+-----+---------+-------+
| TICKET_NO    | decimal(10,0) | NO   | PRI | NULL    |       |
| TICKET_PRICE | varchar(10)   | YES  |     | NULL    |       |
| PARK_CODE    | varchar(10)   | YES  | MUL | NULL    |       |
+--------------+---------------+------+-----+---------+-------+
3 rows in set (0.001 sec)

MariaDB [Theme_park]> INSERT INTO TICKET VALUES (13001,18.99,'FR1001');
ERROR 1452 (23000): Cannot add or update a child row: a foreign key constraint fails (`Theme_park`.`TICKET`, CONSTRAINT `FK_TICKET_PARK` FOREIGN KEY (`PARK_CODE`) REFERENCES `THEMEPARK` (`PARK_CODE`))
MariaDB [Theme_park]> INSERT INTO TICKET VALUES (13001,18.99,'FR1001');
ERROR 1452 (23000): Cannot add or update a child row: a foreign key constraint fails (`Theme_park`.`TICKET`, CONSTRAINT `FK_TICKET_PARK` FOREIGN KEY (`PARK_CODE`) REFERENCES `THEMEPARK` (`PARK_CODE`))
MariaDB [Theme_park]> INSERT INTO TICKET VALUES (13001,18.99,'FR1001')
    -> ;
ERROR 1452 (23000): Cannot add or update a child row: a foreign key constraint fails (`Theme_park`.`TICKET`, CONSTRAINT `FK_TICKET_PARK` FOREIGN KEY (`PARK_CODE`) REFERENCES `THEMEPARK` (`PARK_CODE`))
MariaDB [Theme_park]> INSERT INTO TICKET VALUES(13001,18.99,'FR1001')
    -> ;
ERROR 1452 (23000): Cannot add or update a child row: a foreign key constraint fails (`Theme_park`.`TICKET`, CONSTRAINT `FK_TICKET_PARK` FOREIGN KEY (`PARK_CODE`) REFERENCES `THEMEPARK` (`PARK_CODE`))
MariaDB [Theme_park]> INSERT INTO TICKET VALUES(13001,'FR1001')
    -> ;
ERROR 1136 (21S01): Column count doesn't match value count at row 1
MariaDB [Theme_park]> show tables;
+----------------------+
| Tables_in_Theme_park |
+----------------------+
| ATTRACTION           |
| EMPLOYEE             |
| HOURS                |
| SALES                |
| SALES_LINE           |
| THEMEPARK            |
| TICKET               |
+----------------------+
7 rows in set (0.000 sec)

MariaDB [Theme_park]> describe TICKET;
+--------------+---------------+------+-----+---------+-------+
| Field        | Type          | Null | Key | Default | Extra |
+--------------+---------------+------+-----+---------+-------+
| TICKET_NO    | decimal(10,0) | NO   | PRI | NULL    |       |
| TICKET_PRICE | varchar(10)   | YES  |     | NULL    |       |
| PARK_CODE    | varchar(10)   | YES  | MUL | NULL    |       |
+--------------+---------------+------+-----+---------+-------+
3 rows in set (0.001 sec)

MariaDB [Theme_park]> describe THEMEPARK;
+--------------+-------------+------+-----+---------+-------+
| Field        | Type        | Null | Key | Default | Extra |
+--------------+-------------+------+-----+---------+-------+
| PARK_CODE    | varchar(10) | NO   | PRI | NULL    |       |
| PARK_NAME    | varchar(35) | NO   |     | NULL    |       |
| PARK_CITY    | varchar(50) | NO   |     | NULL    |       |
| PARK_COUNTRY | char(2)     | NO   |     | NULL    |       |
+--------------+-------------+------+-----+---------+-------+
4 rows in set (0.001 sec)

MariaDB [Theme_park]> describe SALES_LINE
    -> ;
+----------------+---------------+------+-----+---------+-------+
| Field          | Type          | Null | Key | Default | Extra |
+----------------+---------------+------+-----+---------+-------+
| TRANSACTION_NO | decimal(10,0) | NO   | PRI | NULL    |       |
| LINE_NO        | decimal(2,0)  | NO   | PRI | NULL    |       |
| TICKET_NO      | decimal(10,0) | NO   | MUL | NULL    |       |
| LINE_QTY       | decimal(4,0)  | NO   |     | 0       |       |
| LINE_PRICE     | decimal(9,2)  | NO   |     | 0.00    |       |
+----------------+---------------+------+-----+---------+-------+
5 rows in set (0.001 sec)

MariaDB [Theme_park]> describe SALES:
    -> 
    -> ;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near ':' at line 1
MariaDB [Theme_park]> describe SALES;
+----------------+---------------+------+-----+---------+-------+
| Field          | Type          | Null | Key | Default | Extra |
+----------------+---------------+------+-----+---------+-------+
| TRANSACTION_NO | decimal(10,0) | NO   | PRI | NULL    |       |
| PARK_CODE      | varchar(10)   | YES  | MUL | NULL    |       |
| SALE_DATE      | date          | NO   |     | NULL    |       |
+----------------+---------------+------+-----+---------+-------+
3 rows in set (0.001 sec)

MariaDB [Theme_park]> show tables;
+----------------------+
| Tables_in_Theme_park |
+----------------------+
| ATTRACTION           |
| EMPLOYEE             |
| HOURS                |
| SALES                |
| SALES_LINE           |
| THEMEPARK            |
| TICKET               |
+----------------------+
7 rows in set (0.000 sec)

MariaDB [Theme_park]> describe ATTRACTION;
+------------------+---------------+------+-----+---------+-------+
| Field            | Type          | Null | Key | Default | Extra |
+------------------+---------------+------+-----+---------+-------+
| ATTRACT_NO       | decimal(10,0) | NO   | PRI | NULL    |       |
| ATTRACT_NAME     | varchar(35)   | YES  |     | NULL    |       |
| ATTRACT_AGE      | decimal(3,0)  | NO   |     | 0       |       |
| ATTRACT_CAPACITY | decimal(3,0)  | NO   |     | NULL    |       |
| PARK_CODE        | varchar(10)   | YES  | MUL | NULL    |       |
+------------------+---------------+------+-----+---------+-------+
5 rows in set (0.001 sec)

MariaDB [Theme_park]> describe TICKET:
    -> ;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near ':' at line 1
MariaDB [Theme_park]> describe TICKET;
+--------------+---------------+------+-----+---------+-------+
| Field        | Type          | Null | Key | Default | Extra |
+--------------+---------------+------+-----+---------+-------+
| TICKET_NO    | decimal(10,0) | NO   | PRI | NULL    |       |
| TICKET_PRICE | varchar(10)   | YES  |     | NULL    |       |
| PARK_CODE    | varchar(10)   | YES  | MUL | NULL    |       |
+--------------+---------------+------+-----+---------+-------+
3 rows in set (0.001 sec)

MariaDB [Theme_park]> show tables;
+----------------------+
| Tables_in_Theme_park |
+----------------------+
| ATTRACTION           |
| EMPLOYEE             |
| HOURS                |
| SALES                |
| SALES_LINE           |
| THEMEPARK            |
| TICKET               |
+----------------------+
7 rows in set (0.000 sec)

MariaDB [Theme_park]> DROP TABLE TICKET;
ERROR 1451 (23000): Cannot delete or update a parent row: a foreign key constraint fails
MariaDB [Theme_park]> update TICKET;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near '' at line 1
MariaDB [Theme_park]> update TICKET
    -> TICKET_TYPE VARCHAR(10),
    -> 
    -> ;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'VARCHAR(10),' at line 2
MariaDB [Theme_park]> show databases;
+--------------------+
| Database           |
+--------------------+
| Theme_park         |
| information_schema |
| mysql              |
| performance_schema |
| phpmyadmin         |
| test               |
+--------------------+
6 rows in set (0.000 sec)

MariaDB [Theme_park]> DROP TABLES;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near '' at line 1
MariaDB [Theme_park]> DROP TABLE TICKET;
ERROR 1451 (23000): Cannot delete or update a parent row: a foreign key constraint fails
MariaDB [Theme_park]> DROP Theme_park;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'Theme_park' at line 1
MariaDB [Theme_park]> DROP database Theme_park;
Query OK, 7 rows affected, 2 warnings (0.065 sec)

MariaDB [(none)]> show databases;
+--------------------+
| Database           |
+--------------------+
| information_schema |
| mysql              |
| performance_schema |
| phpmyadmin         |
| test               |
+--------------------+
5 rows in set (0.000 sec)

MariaDB [(none)]> CREATE DATABASE THEME_PARK;
Query OK, 1 row affected (0.000 sec)

MariaDB [(none)]> show databases;
+--------------------+
| Database           |
+--------------------+
| THEME_PARK         |
| information_schema |
| mysql              |
| performance_schema |
| phpmyadmin         |
| test               |
+--------------------+
6 rows in set (0.000 sec)

MariaDB [(none)]> USE THEME_PARK;
Database changed
MariaDB [THEME_PARK]> CREATE TABLE THEMEPARK (
    -> PARK_CODE VARCHAR(10) PRIMARY KEY,
    -> PARK_NAME VARCHAR(35) NOT NULL,
    -> PARK_CITY VARCHAR(50) NOT NULL,
    -> PARK_COUNTRY CHAR(2) NOT NULL);
Query OK, 0 rows affected (0.010 sec)

MariaDB [THEME_PARK]> CREATE TABLE EMPLOYEE(
    -> EMP_NUM NUMERIC(4) PRIMARY KEY,
    -> EMP_TITLE VARCHAR(4),
    -> EMP_LNAME VARCHAR(15) NOT NULL,
    -> EMP_FNAME VARCHAR(15) NOT NULL,
    -> EMP_DOB DATE NOT NULL,
    -> EMP_HIRE_DATE DATE,
    -> EMP_AREA_CODE VARCHAR(4) NOT NULL,
    -> EMP_PHONE VARCHAR(12)NOT NULL,
    -> PARK_CODE VARCHAR(10),
    -> INDEX (PARK_CODE),
    -> CONSTRAINT FK_EMP_PARK FOREIGN KEY(PARK_CODE) REFERENCES THEMEPARK(PARK_CODE));
Query OK, 0 rows affected (0.013 sec)

MariaDB [THEME_PARK]> CREATE TABLE TICKET (
    -> TICKET_NO NUMERIC(10) PRIMARY KEY,
    -> TICKET_PRICE VARCHAR(10),
    -> TICKET_TYPE VARCHAR(10),
    -> PARK_CODE VARCHAR(10),
    -> INDEX (PARK_CODE),
    -> CONSTRAINT FK_TICKET_PARK FOREIGN KEY(PARK_CODE) REFERENCES THEMEPARK(PARK_CODE));
Query OK, 0 rows affected (0.012 sec)

MariaDB [THEME_PARK]> CREATE TABLE ATTRACTION (
    -> ATTRACT_NO NUMERIC(10) PRIMARY KEY,
    -> ATTRACT_NAME VARCHAR(35),
    -> ATTRACT_AGE NUMERIC(3) DEFAULT 0 NOT NULL,
    -> ATTRACT_CAPACITY NUMERIC(3) NOT NULL,
    -> PARK_CODE VARCHAR(10),
    -> INDEX (PARK_CODE),
    -> CONSTRAINT FK_ATTRACT_PARK FOREIGN KEY(PARK_CODE) REFERENCES THEMEPARK(PARK_CODE));
Query OK, 0 rows affected (0.013 sec)

MariaDB [THEME_PARK]> CREATE TABLE HOURS (
    -> EMP_NUM NUMERIC(4),
    -> ATTRACT_NO NUMERIC(10),
    -> HOURS_PER_ATTRACT NUMERIC(2) NOT NULL,
    -> HOUR_RATE NUMERIC(4,2) NOT NULL,
    -> DATE_WORKED DATE NOT NULL,
    -> INDEX (EMP_NUM),
    -> INDEX (ATTRACT_NO),
    -> CONSTRAINT PK_HOURS PRIMARY KEY (EMP_NUM, ATTRACT_NO, DATE_WORKED),
    -> CONSTRAINT FK_HOURS_EMP FOREIGN KEY (EMP_NUM) REFERENCES EMPLOYEE(EMP_NUM),
    -> CONSTRAINT FK_HOURS_ATTRACT FOREIGN KEY (ATTRACT_NO) REFERENCES ATTRACTION(ATTRACT_NO));
Query OK, 0 rows affected, 1 warning (0.015 sec)

MariaDB [THEME_PARK]> CREATE TABLE SALES (
    -> TRANSACTION_NO NUMERIC PRIMARY KEY,
    -> PARK_CODE VARCHAR(10),
    -> SALE_DATE DATE NOT NULL,
    -> INDEX (PARK_CODE),
    -> CONSTRAINT FK_SALES_PARK FOREIGN KEY(PARK_CODE) REFERENCES THEMEPARK(PARK_CODE));
Query OK, 0 rows affected (0.014 sec)

MariaDB [THEME_PARK]> CREATE TABLE SALES_LINE (
    -> TRANSACTION_NO NUMERIC,
    -> LINE_NO NUMERIC(2,0) NOT NULL,
    -> TICKET_NO NUMERIC(10) NOT NULL,
    -> LINE_QTY NUMERIC(4) DEFAULT 0 NOT NULL,
    -> LINE_PRICE NUMERIC(9,2) DEFAULT 0.00 NOT NULL,
    -> INDEX (TRANSACTION_NO),
    -> INDEX (TICKET_NO),
    -> CONSTRAINT PK_SALES_LINE PRIMARY KEY (TRANSACTION_NO, LINE_NO),
    -> CONSTRAINT FK_SALES_LINE_SALES FOREIGN KEY (TRANSACTION_NO) REFERENCES SALES(TRANSACTION_NO),
    -> CONSTRAINT FK_SALES_LINE_TICKET FOREIGN KEY (TICKET_NO) REFERENCES TICKET(TICKET_NO));
Query OK, 0 rows affected, 1 warning (0.016 sec)

MariaDB [THEME_PARK]> show tables;
+----------------------+
| Tables_in_THEME_PARK |
+----------------------+
| ATTRACTION           |
| EMPLOYEE             |
| HOURS                |
| SALES                |
| SALES_LINE           |
| THEMEPARK            |
| TICKET               |
+----------------------+
7 rows in set (0.000 sec)

MariaDB [THEME_PARK]> sudo /opt/lampp/bin/mysqldump -u root -p THEME_PARK > /home/shafeen/Desktop/newthemepark.sql
    -> ;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'sudo /opt/lampp/bin/mysqldump -u root -p THEME_PARK > /home/shafeen/Desktop/n...' at line 1
MariaDB [THEME_PARK]> sudo /opt/lampp/bin/mysqldump -u root -p THEMEPARK > /home/shafeen/Desktop/newthemepark.sql
    -> ;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'sudo /opt/lampp/bin/mysqldump -u root -p THEMEPARK > /home/shafeen/Desktop/ne...' at line 1
MariaDB [THEME_PARK]> exit
Bye
shafeen@shafeen-Dell-G15-5515 ~> sudo /opt/lampp/bin/mysqldump -u root -p THEME_PARK > /home/shafeen/Desktop/newthemepark.sql
[sudo] password for shafeen: 
Enter password: 
shafeen@shafeen-Dell-G15-5515 ~> fish
Welcome to fish, the friendly interactive shell
Type help for instructions on how to use fish
shafeen@shafeen-Dell-G15-5515 ~> sudo /opt/lampp/bin/mysql -u root -p
Enter password: 
Welcome to the MariaDB monitor.  Commands end with ; or \g.
Your MariaDB connection id is 22
Server version: 10.4.32-MariaDB Source distribution

Copyright (c) 2000, 2018, Oracle, MariaDB Corporation Ab and others.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

MariaDB [(none)]> USE THEMEPARK
ERROR 1049 (42000): Unknown database 'THEMEPARK'
MariaDB [(none)]> USE THEMEPARK'
ERROR 1049 (42000): Unknown database 'THEMEPARK''
MariaDB [(none)]> 
MariaDB [(none)]> USE THEMEPARK;
ERROR 1049 (42000): Unknown database 'THEMEPARK'
MariaDB [(none)]> SHOW DATABASES;
+--------------------+
| Database           |
+--------------------+
| THEME_PARK         |
| information_schema |
| mysql              |
| performance_schema |
| phpmyadmin         |
| test               |
+--------------------+
6 rows in set (0.000 sec)

MariaDB [(none)]> USE THEME_PARK;
Reading table information for completion of table and column names
You can turn off this feature to get a quicker startup with -A

Database changed
MariaDB [THEME_PARK]> show tables;
+----------------------+
| Tables_in_THEME_PARK |
+----------------------+
| ATTRACTION           |
| EMPLOYEE             |
| HOURS                |
| SALES                |
| SALES_LINE           |
| THEMEPARK            |
| TICKET               |
+----------------------+
7 rows in set (0.000 sec)

MariaDB [THEME_PARK]> describe TICKET:
    -> 
    -> ;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near ':' at line 1
MariaDB [THEME_PARK]> describe TICKET;
+--------------+---------------+------+-----+---------+-------+
| Field        | Type          | Null | Key | Default | Extra |
+--------------+---------------+------+-----+---------+-------+
| TICKET_NO    | decimal(10,0) | NO   | PRI | NULL    |       |
| TICKET_PRICE | varchar(10)   | YES  |     | NULL    |       |
| TICKET_TYPE  | varchar(10)   | YES  |     | NULL    |       |
| PARK_CODE    | varchar(10)   | YES  | MUL | NULL    |       |
+--------------+---------------+------+-----+---------+-------+
4 rows in set (0.001 sec)

MariaDB [THEME_PARK]> Bye
shafeen@shafeen-Dell-G15-5515 ~> sudo /opt/lampp/bin/mysql -u root -p
Enter password: 
Welcome to the MariaDB monitor.  Commands end with ; or \g.
Your MariaDB connection id is 23
Server version: 10.4.32-MariaDB Source distribution

Copyright (c) 2000, 2018, Oracle, MariaDB Corporation Ab and others.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

MariaDB [(none)]> USE THEME_PARK;
Reading table information for completion of table and column names
You can turn off this feature to get a quicker startup with -A

Database changed
MariaDB [THEME_PARK]> show tables;
+----------------------+
| Tables_in_THEME_PARK |
+----------------------+
| ATTRACTION           |
| EMPLOYEE             |
| HOURS                |
| SALES                |
| SALES_LINE           |
| THEMEPARK            |
| TICKET               |
+----------------------+
7 rows in set (0.000 sec)

MariaDB [THEME_PARK]> source /home/shafeen/Desktop/newthemepark.sql;
Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.007 sec)

Query OK, 0 rows affected (0.006 sec)

Query OK, 0 rows affected (0.007 sec)

Query OK, 0 rows affected (0.007 sec)

Query OK, 0 rows affected (0.005 sec)

Query OK, 0 rows affected (0.005 sec)

Query OK, 0 rows affected (0.006 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.012 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.011 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.015 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.012 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.014 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.009 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.001 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.013 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

Query OK, 0 rows affected (0.000 sec)

MariaDB [THEME_PARK]> SHOW TABLES;
+----------------------+
| Tables_in_THEME_PARK |
+----------------------+
| ATTRACTION           |
| EMPLOYEE             |
| HOURS                |
| SALES                |
| SALES_LINE           |
| THEMEPARK            |
| TICKET               |
+----------------------+
7 rows in set (0.000 sec)

MariaDB [THEME_PARK]> DESCRIBE TICKET';
    '> ;
    '> ;
    '> SHO
    '> ;
    '> DESCRIBE TICKET;
    '> SA
    '> D
    '> SD
    '> S
    '> S
    '> S
    '> S
    '> S
    '> SS
    '> SE
    '> EXOT
    '> EXIT
    '> exit
    '> Ctrl-C -- exit!
Aborted
shafeen@shafeen-Dell-G15-5515 ~ [1]> sudo /opt/lampp/bin/mysql -u root -p
Enter password: 
Welcome to the MariaDB monitor.  Commands end with ; or \g.
Your MariaDB connection id is 24
Server version: 10.4.32-MariaDB Source distribution

Copyright (c) 2000, 2018, Oracle, MariaDB Corporation Ab and others.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

MariaDB [(none)]> USE THEME_PARK;
Reading table information for completion of table and column names
You can turn off this feature to get a quicker startup with -A

Database changed
MariaDB [THEME_PARK]> show tables;
+----------------------+
| Tables_in_THEME_PARK |
+----------------------+
| ATTRACTION           |
| EMPLOYEE             |
| HOURS                |
| SALES                |
| SALES_LINE           |
| THEMEPARK            |
| TICKET               |
+----------------------+
7 rows in set (0.000 sec)

MariaDB [THEME_PARK]> describe TICKET;
+--------------+---------------+------+-----+---------+-------+
| Field        | Type          | Null | Key | Default | Extra |
+--------------+---------------+------+-----+---------+-------+
| TICKET_NO    | decimal(10,0) | NO   | PRI | NULL    |       |
| TICKET_PRICE | varchar(10)   | YES  |     | NULL    |       |
| TICKET_TYPE  | varchar(10)   | YES  |     | NULL    |       |
| PARK_CODE    | varchar(10)   | YES  | MUL | NULL    |       |
+--------------+---------------+------+-----+---------+-------+
4 rows in set (0.001 sec)

MariaDB [THEME_PARK]> INSERT INTO THEMEPARK VALUES ('FR1001','FairyLand','PARIS','FR');
Query OK, 1 row affected (0.003 sec)

MariaDB [THEME_PARK]> INSERT INTO THEMEPARK VALUES ('UK3452','PleasureLand','STOKE','UK');
Query OK, 1 row affected (0.003 sec)

MariaDB [THEME_PARK]> INSERT INTO TICKET VALUES (13001,18.99,'Child','FR1001');
Query OK, 1 row affected (0.003 sec)

MariaDB [THEME_PARK]> INSERT INTO TICKET VALUES (13002,34.99,'Adult','FR1001');
Query OK, 1 row affected (0.002 sec)

MariaDB [THEME_PARK]> INSERT INTO TICKET VALUES (13003,20.99,'Senior','FR1001');
Query OK, 1 row affected (0.004 sec)

MariaDB [THEME_PARK]> INSERT INTO TICKET VALUES (88567,22.50,'Child','UK3452');
Query OK, 1 row affected (0.001 sec)

MariaDB [THEME_PARK]> INSERT INTO TICKET VALUES (88568,42.10,'Adult','UK3452');INSERT INTO TICKET VALUES (89720,10.99,'Senior','UK3452');
Query OK, 1 row affected (0.003 sec)

Query OK, 1 row affected (0.001 sec)

MariaDB [THEME_PARK]> SELECT * FROM THEMEPARK;
+-----------+--------------+-----------+--------------+
| PARK_CODE | PARK_NAME    | PARK_CITY | PARK_COUNTRY |
+-----------+--------------+-----------+--------------+
| FR1001    | FairyLand    | PARIS     | FR           |
| UK3452    | PleasureLand | STOKE     | UK           |
+-----------+--------------+-----------+--------------+
2 rows in set (0.000 sec)

MariaDB [THEME_PARK]> SELECT ATTRACT_NO, ATTRACT_NAME, ATTRACT_CAPACITY
    -> FROM ATTRACTION;
Empty set (0.000 sec)

MariaDB [THEME_PARK]> SELECT EMP_NUM, EMP_LNAME, EMP_FNAME,
    -> EMP_HIRE_DATE FROM EMPLOYEE;
Empty set (0.000 sec)

MariaDB [THEME_PARK]> INSERT INTO THEMEPARK VALUES ('FR1001', 'FairyLand', 'PARIS', 'FR');
ERROR 1062 (23000): Duplicate entry 'FR1001' for key 'PRIMARY'
MariaDB [THEME_PARK]> INSERT INTO THEMEPARK VALUES ('NL1202', 'Efling', 'NOORD', 'INL');
ERROR 1406 (22001): Data too long for column 'PARK_COUNTRY' at row 1
MariaDB [THEME_PARK]> INSERT INTO THEMEPARK VALUES ('SP4533', 'Adventure Port', 'BARCELONA', 'SP');
Query OK, 1 row affected (0.002 sec)

MariaDB [THEME_PARK]> INSERT INTO THEMEPARK VALUES ('SW2323', 'Labyrinthe', 'LAUSANNE', 'SV');
Query OK, 1 row affected (0.002 sec)

MariaDB [THEME_PARK]> INSERT INTO THEMEPARK VALUES ('UK2622', 'MiniLand', 'WINDSOR', 'UK');
Query OK, 1 row affected (0.004 sec)

MariaDB [THEME_PARK]> INSERT INTO THEMEPARK VALUES ('UK3452', 'PleasureLand', 'STOKE', 'UK');
ERROR 1062 (23000): Duplicate entry 'UK3452' for key 'PRIMARY'
MariaDB [THEME_PARK]> INSERT INTO THEMEPARK VALUES ('FR1001', 'FairyLand', 'PARIS', 'FR');
ERROR 1062 (23000): Duplicate entry 'FR1001' for key 'PRIMARY'
MariaDB [THEME_PARK]> INSERT INTO THEMEPARK VALUES ('NL1202', 'Efling', 'NOORD', 'INL');
ERROR 1406 (22001): Data too long for column 'PARK_COUNTRY' at row 1
MariaDB [THEME_PARK]> show tables;
+----------------------+
| Tables_in_THEME_PARK |
+----------------------+
| ATTRACTION           |
| EMPLOYEE             |
| HOURS                |
| SALES                |
| SALES_LINE           |
| THEMEPARK            |
| TICKET               |
+----------------------+
7 rows in set (0.000 sec)

MariaDB [THEME_PARK]> describe THEMEPARK;
+--------------+-------------+------+-----+---------+-------+
| Field        | Type        | Null | Key | Default | Extra |
+--------------+-------------+------+-----+---------+-------+
| PARK_CODE    | varchar(10) | NO   | PRI | NULL    |       |
| PARK_NAME    | varchar(35) | NO   |     | NULL    |       |
| PARK_CITY    | varchar(50) | NO   |     | NULL    |       |
| PARK_COUNTRY | char(2)     | NO   |     | NULL    |       |
+--------------+-------------+------+-----+---------+-------+
4 rows in set (0.001 sec)

MariaDB [THEME_PARK]> INSERT INTO THEMEPARK VALUES ('NL1202', 'Efling', 'NOORD', 'IN');
Query OK, 1 row affected (0.003 sec)

MariaDB [THEME_PARK]> INSERT INTO THEMEPARK VALUES ('SP4533', 'Adventure Port', 'BARCELONA', 'SP');
ERROR 1062 (23000): Duplicate entry 'SP4533' for key 'PRIMARY'
MariaDB [THEME_PARK]> INSERT INTO THEMEPARK VALUES ('SW2323', 'Labyrinthe', 'LAUSANNE', 'SV');
ERROR 1062 (23000): Duplicate entry 'SW2323' for key 'PRIMARY'
MariaDB [THEME_PARK]> INSERT INTO THEMEPARK VALUES ('UK2622', 'MiniLand', 'WINDSOR', 'UK');
ERROR 1062 (23000): Duplicate entry 'UK2622' for key 'PRIMARY'
MariaDB [THEME_PARK]> INSERT INTO THEMEPARK VALUES ('UK3452', 'PleasureLand', 'STOKE', 'UK');
ERROR 1062 (23000): Duplicate entry 'UK3452' for key 'PRIMARY'
MariaDB [THEME_PARK]> INSERT INTO THEMEPARK VALUES ('ZA1342', 'GoldTown', 'JOHANNESBURG', 'ZA');
Query OK, 1 row affected (0.003 sec)

MariaDB [THEME_PARK]> INSERT INTO ATTRACTION VALUES (10034, 'ThunderCoaster',18, 34,'FR1001');
Query OK, 1 row affected (0.003 sec)

MariaDB [THEME_PARK]> INSERT INTO ATTRACTION VALUES (10056, 'SpinningTeacups',16, 62,'FR1001');
Query OK, 1 row affected (0.002 sec)

MariaDB [THEME_PARK]> INSERT INTO ATTRACTION VALUES (10067, 'FlightToStars', 32,24,'SP4533');
Query OK, 1 row affected (0.003 sec)

MariaDB [THEME_PARK]> INSERT INTO ATTRACTION VALUES (18878, 'Ant-Trap', 12,30,'ZA1342');
Query OK, 1 row affected (0.002 sec)

MariaDB [THEME_PARK]> INSERT INTO ATTRACTION VALUES (10082, NULL,42, 40,'FR1001');
Query OK, 1 row affected (0.002 sec)

MariaDB [THEME_PARK]> INSERT INTO ATTRACTION VALUES (10098, 'Carnival', 8,120,'ZA1342');
Query OK, 1 row affected (0.002 sec)

MariaDB [THEME_PARK]> INSERT INTO ATTRACTION VALUES (20056, '3D-Lego_Show',12, 200,'FR1001');
Query OK, 1 row affected (0.001 sec)

MariaDB [THEME_PARK]> INSERT INTO ATTRACTION VALUES (30011, 'BlackHole2', 16,34,'UK2622');
Query OK, 1 row affected (0.002 sec)

MariaDB [THEME_PARK]> INSERT INTO ATTRACTION VALUES (30012, 'Pirates', 15,42,'UK2622');
Query OK, 1 row affected (0.002 sec)

MariaDB [THEME_PARK]> INSERT INTO ATTRACTION VALUES (30044, 'UnderSeaWord',16, 80,'SP4533');
Query OK, 1 row affected (0.001 sec)

MariaDB [THEME_PARK]> INSERT INTO ATTRACTION VALUES (98764, 'Gold Rush', 17,1,'FR1001');
Query OK, 1 row affected (0.003 sec)

MariaDB [THEME_PARK]> SELECT ATTRACT_NO, ATTRACT_NAME, ATTRACT_CAPACITY
    -> FROM ATTRACTION;
+------------+-----------------+------------------+
| ATTRACT_NO | ATTRACT_NAME    | ATTRACT_CAPACITY |
+------------+-----------------+------------------+
|      10034 | ThunderCoaster  |               34 |
|      10056 | SpinningTeacups |               62 |
|      10067 | FlightToStars   |               24 |
|      10082 | NULL            |               40 |
|      10098 | Carnival        |              120 |
|      18878 | Ant-Trap        |               30 |
|      20056 | 3D-Lego_Show    |              200 |
|      30011 | BlackHole2      |               34 |
|      30012 | Pirates         |               42 |
|      30044 | UnderSeaWord    |               80 |
|      98764 | Gold Rush       |                1 |
+------------+-----------------+------------------+
11 rows in set (0.001 sec)

MariaDB [THEME_PARK]> SELECT EMP_NUM, EMP_LNAME, EMP_FNAME,
    -> EMP_HIRE_DATE FROM EMPLOYEE;
Empty set (0.000 sec)

MariaDB [THEME_PARK]> INSERT INTO EMPLOYEE VALUES (1234, 'Mr.', 'Doe', 'John', '2000-01-01', '2021-01-01',
    -> '123', '123-456-7890', 'FR1001');
Query OK, 1 row affected (0.003 sec)

MariaDB [THEME_PARK]> INSERT INTO EMPLOYEE VALUES (5678, 'Mrs.', 'Smith', 'Jane', '1995-05-15', '2020-02-
    '> 15', '456', '987-654-3210', 'NL1202');
ERROR 1292 (22007): Incorrect date value: '2020-02-
15' for column `THEME_PARK`.`EMPLOYEE`.`EMP_HIRE_DATE` at row 1
MariaDB [THEME_PARK]> INSERT INTO EMPLOYEE VALUES(9101, 'Dr.', 'Johnson', 'Robert' , '1980-12-05', '2018-
    '> 08-10', '789', '555-123-4567', 'FR1001');
ERROR 1292 (22007): Incorrect date value: '2018-
08-10' for column `THEME_PARK`.`EMPLOYEE`.`EMP_HIRE_DATE` at row 1
MariaDB [THEME_PARK]> INSERT INTO EMPLOYEE VALUES (2222, 'Miss', 'Williams', 'Emily', '1992-08-23', '2017-
    '> 06-20', '321', '333-444-5555', 'NL1202');
ERROR 1292 (22007): Incorrect date value: '2017-
06-20' for column `THEME_PARK`.`EMPLOYEE`.`EMP_HIRE_DATE` at row 1
MariaDB [THEME_PARK]> INSERT INTO EMPLOYEE VALUES (3333, 'Mr.', 'Brown', 'Michael' , '1985-04-10', '2015-
    '> 12-03', '555', '888-777-9999', 'FR1001');
ERROR 1292 (22007): Incorrect date value: '2015-
12-03' for column `THEME_PARK`.`EMPLOYEE`.`EMP_HIRE_DATE` at row 1
MariaDB [THEME_PARK]> INSERT INTO EMPLOYEE VALUES (4444, 'Ms.', 'Davis', 'Sophia', '1990-07-07', '2016-09-
    '> 25', '666', '222-111-3333','SP4533');
ERROR 1292 (22007): Incorrect date value: '2016-09-
25' for column `THEME_PARK`.`EMPLOYEE`.`EMP_HIRE_DATE` at row 1
MariaDB [THEME_PARK]> INSERT INTO EMPLOYEE VALUES (5555, 'Dr.', 'Lee', 'Andrew', '1978-11-30', '2014-03-
    '> 12', '888', '444-555-6666', 'SW2323');
ERROR 1292 (22007): Incorrect date value: '2014-03-
12' for column `THEME_PARK`.`EMPLOYEE`.`EMP_HIRE_DATE` at row 1
MariaDB [THEME_PARK]> INSERT INTO EMPLOYEE VALUES(6666, 'Mrs.', 'Taylor', 'Olivia', '1988-02-18', '2013-07-
    '> 08', '999', '777-888-0000', 'UK2622');
ERROR 1292 (22007): Incorrect date value: '2013-07-
08' for column `THEME_PARK`.`EMPLOYEE`.`EMP_HIRE_DATE` at row 1
MariaDB [THEME_PARK]> INSERT INTO EMPLOYEE VALUES(7777, 'Mr.', 'Harris', 'David', '1997-06-05', '2012-05-
    '> 22', '111', '666-333-9999', 'UK3452');
ERROR 1292 (22007): Incorrect date value: '2012-05-
22' for column `THEME_PARK`.`EMPLOYEE`.`EMP_HIRE_DATE` at row 1
MariaDB [THEME_PARK]> INSERT INTO EMPLOYEE VALUES (8888, 'Miss', 'Garcia', 'Isabella' , '1983-09-12', '2011-
    '> 10-18', '444', '999-222-1111', 'ZA1342');
ERROR 1292 (22007): Incorrect date value: '2011-
10-18' for column `THEME_PARK`.`EMPLOYEE`.`EMP_HIRE_DATE` at row 1
MariaDB [THEME_PARK]> INSERT INTO EMPLOYEE VALUES (1234, 'Mr.','Doe','John','2000-01-01','2021-01-01','123','123-456-7890','FR1001');
ERROR 1062 (23000): Duplicate entry '1234' for key 'PRIMARY'
MariaDB [THEME_PARK]> INSERT INTO EMPLOYEE VALUES (5678, 'Mrs.','Smith','Jane','1995-05-15','2020-02-15','456','987-654-3210','NL1202');
Query OK, 1 row affected (0.003 sec)

MariaDB [THEME_PARK]> INSERT INTO EMPLOYEE VALUES(9101, 'Dr.','Johnson','Robert' ,'1980-12-05','2018-08-10','789','555-123-4567','FR1001');
Query OK, 1 row affected (0.004 sec)

MariaDB [THEME_PARK]> INSERT INTO EMPLOYEE VALUES (2222, 'Miss','Williams','Emily','1992-08-23','2017-06-20','321','333-444-5555','NL1202');
Query OK, 1 row affected (0.002 sec)

MariaDB [THEME_PARK]> INSERT INTO EMPLOYEE VALUES (3333, 'Mr.','Brown','Michael' ,'1985-04-10','2015-12-03','555','888-777-9999','FR1001');
Query OK, 1 row affected (0.002 sec)

MariaDB [THEME_PARK]> INSERT INTO EMPLOYEE VALUES (4444, 'Ms.','Davis','Sophia','1990-07-07','2016-09-25','666','222-111-3333','SP4533');
Query OK, 1 row affected (0.002 sec)

MariaDB [THEME_PARK]> INSERT INTO EMPLOYEE VALUES (5555, 'Dr.','Lee','Andrew','1978-11-30','2014-03-12','888','444-555-6666','SW2323');
Query OK, 1 row affected (0.002 sec)

MariaDB [THEME_PARK]> INSERT INTO EMPLOYEE VALUES(6666, 'Mrs.','Taylor','Olivia','1988-02-18','2013-07-08','999','777-888-0000','UK2622');
Query OK, 1 row affected (0.002 sec)

MariaDB [THEME_PARK]> INSERT INTO EMPLOYEE VALUES(7777, 'Mr.','Harris','David','1997-06-05','2012-05-22','111','666-333-9999','UK3452');
Query OK, 1 row affected (0.002 sec)

MariaDB [THEME_PARK]> INSERT INTO EMPLOYEE VALUES (8888, 'Miss','Garcia','Isabella','1983-09-12','2011-10-18','444''999-222-1111','ZA1342');
ERROR 1136 (21S01): Column count doesn't match value count at row 1
MariaDB [THEME_PARK]> INSERT INTO EMPLOYEE VALUES (8888, 'Miss','Garcia','Isabella','1983-09-12','2011-10-18','444','999-222-1111','ZA1342');
Query OK, 1 row affected (0.003 sec)

MariaDB [THEME_PARK]> SELECT ATTRACT_NO, ATTRACT_NAME, ATTRACT_CAPACITY
    -> FROM ATTRACTION;
+------------+-----------------+------------------+
| ATTRACT_NO | ATTRACT_NAME    | ATTRACT_CAPACITY |
+------------+-----------------+------------------+
|      10034 | ThunderCoaster  |               34 |
|      10056 | SpinningTeacups |               62 |
|      10067 | FlightToStars   |               24 |
|      10082 | NULL            |               40 |
|      10098 | Carnival        |              120 |
|      18878 | Ant-Trap        |               30 |
|      20056 | 3D-Lego_Show    |              200 |
|      30011 | BlackHole2      |               34 |
|      30012 | Pirates         |               42 |
|      30044 | UnderSeaWord    |               80 |
|      98764 | Gold Rush       |                1 |
+------------+-----------------+------------------+
11 rows in set (0.000 sec)

MariaDB [THEME_PARK]> SELECT EMP_NUM, EMP_LNAME, EMP_FNAME,
    -> EMP_HIRE_DATE FROM EMPLOYEE;
+---------+-----------+-----------+---------------+
| EMP_NUM | EMP_LNAME | EMP_FNAME | EMP_HIRE_DATE |
+---------+-----------+-----------+---------------+
|    1234 | Doe       | John      | 2021-01-01    |
|    2222 | Williams  | Emily     | 2017-06-20    |
|    3333 | Brown     | Michael   | 2015-12-03    |
|    4444 | Davis     | Sophia    | 2016-09-25    |
|    5555 | Lee       | Andrew    | 2014-03-12    |
|    5678 | Smith     | Jane      | 2020-02-15    |
|    6666 | Taylor    | Olivia    | 2013-07-08    |
|    7777 | Harris    | David     | 2012-05-22    |
|    8888 | Garcia    | Isabella  | 2011-10-18    |
|    9101 | Johnson   | Robert    | 2018-08-10    |
+---------+-----------+-----------+---------------+
10 rows in set (0.000 sec)

MariaDB [THEME_PARK]> 
MariaDB [THEME_PARK]> 
MariaDB [THEME_PARK]> 
MariaDB [THEME_PARK]> 
MariaDB [THEME_PARK]> exit
Bye
shafeen@shafeen-Dell-G15-5515 ~> sudo /opt/lampp/bin/mysqldump -u root -p THEME_PARK > /home/shafeen/Desktop/newthemepark_after_addingData.sql
Enter password: 
shafeen@shafeen-Dell-G15-5515 ~> UPDATE ATTRACTION
UPDATE: command not found
shafeen@shafeen-Dell-G15-5515 ~ [127]> sudo /opt/lampp/bin/mysql -u root -p
Enter password: 
Welcome to the MariaDB monitor.  Commands end with ; or \g.
Your MariaDB connection id is 26
Server version: 10.4.32-MariaDB Source distribution

Copyright (c) 2000, 2018, Oracle, MariaDB Corporation Ab and others.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

MariaDB [(none)]> use THEME_PARK;
Reading table information for completion of table and column names
You can turn off this feature to get a quicker startup with -A

Database changed
MariaDB [THEME_PARK]> UPDATE ATTRACTION
    -> SETATTRACT_AGE = 14
    -> SELECT
    -> *
    -> FROM
    -> 
    -> Ctrl-C -- exit!
Aborted
shafeen@shafeen-Dell-G15-5515 ~ [1]> sudo /opt/lampp/bin/mysql -u root -p
Enter password: 
Welcome to the MariaDB monitor.  Commands end with ; or \g.
Your MariaDB connection id is 27
Server version: 10.4.32-MariaDB Source distribution

Copyright (c) 2000, 2018, Oracle, MariaDB Corporation Ab and others.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

MariaDB [(none)]> USE THEME_PARK;
Reading table information for completion of table and column names
You can turn off this feature to get a quicker startup with -A

Database changed
MariaDB [THEME_PARK]> UPDATEATTRACTION
    -> Ctrl-C -- exit!
Aborted
shafeen@shafeen-Dell-G15-5515 ~ [1]> sudo /opt/lampp/bin/mysql -u root -p
Enter password: 
Welcome to the MariaDB monitor.  Commands end with ; or \g.
Your MariaDB connection id is 28
Server version: 10.4.32-MariaDB Source distribution

Copyright (c) 2000, 2018, Oracle, MariaDB Corporation Ab and others.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

MariaDB [(none)]> USE THEME_PARK:
ERROR 1049 (42000): Unknown database 'THEME_PARK:'
MariaDB [(none)]> USE THEME_PARK;
Reading table information for completion of table and column names
You can turn off this feature to get a quicker startup with -A

Database changed
MariaDB [THEME_PARK]> show tables;
+----------------------+
| Tables_in_THEME_PARK |
+----------------------+
| ATTRACTION           |
| EMPLOYEE             |
| HOURS                |
| SALES                |
| SALES_LINE           |
| THEMEPARK            |
| TICKET               |
+----------------------+
7 rows in set (0.000 sec)

MariaDB [THEME_PARK]> SELECT * ATTRACTION;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'ATTRACTION' at line 1
MariaDB [THEME_PARK]> describe ATTRACTION;
+------------------+---------------+------+-----+---------+-------+
| Field            | Type          | Null | Key | Default | Extra |
+------------------+---------------+------+-----+---------+-------+
| ATTRACT_NO       | decimal(10,0) | NO   | PRI | NULL    |       |
| ATTRACT_NAME     | varchar(35)   | YES  |     | NULL    |       |
| ATTRACT_AGE      | decimal(3,0)  | NO   |     | 0       |       |
| ATTRACT_CAPACITY | decimal(3,0)  | NO   |     | NULL    |       |
| PARK_CODE        | varchar(10)   | YES  | MUL | NULL    |       |
+------------------+---------------+------+-----+---------+-------+
5 rows in set (0.001 sec)

MariaDB [THEME_PARK]> SELECT ATTRACTION_NO
    -> FROM ATTRACTION;
ERROR 1054 (42S22): Unknown column 'ATTRACTION_NO' in 'field list'
MariaDB [THEME_PARK]> SELECT ATTRACT_NO FROM ATTRACTION;
+------------+
| ATTRACT_NO |
+------------+
|      10034 |
|      10056 |
|      10082 |
|      20056 |
|      98764 |
|      10067 |
|      30044 |
|      30011 |
|      30012 |
|      10098 |
|      18878 |
+------------+
11 rows in set (0.000 sec)

MariaDB [THEME_PARK]> UPDATE ATTRACTION
    -> SET ATTRACT_AGE=14
    -> SELECT * FROM ATTRACTION;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'SELECT * FROM ATTRACTION' at line 3
MariaDB [THEME_PARK]> UPDATE ATTRACTION SET ATTRACT_AGE=14; SELECT * FROM ATTRACTION;
Query OK, 11 rows affected (0.004 sec)
Rows matched: 11  Changed: 11  Warnings: 0

+------------+-----------------+-------------+------------------+-----------+
| ATTRACT_NO | ATTRACT_NAME    | ATTRACT_AGE | ATTRACT_CAPACITY | PARK_CODE |
+------------+-----------------+-------------+------------------+-----------+
|      10034 | ThunderCoaster  |          14 |               34 | FR1001    |
|      10056 | SpinningTeacups |          14 |               62 | FR1001    |
|      10067 | FlightToStars   |          14 |               24 | SP4533    |
|      10082 | NULL            |          14 |               40 | FR1001    |
|      10098 | Carnival        |          14 |              120 | ZA1342    |
|      18878 | Ant-Trap        |          14 |               30 | ZA1342    |
|      20056 | 3D-Lego_Show    |          14 |              200 | FR1001    |
|      30011 | BlackHole2      |          14 |               34 | UK2622    |
|      30012 | Pirates         |          14 |               42 | UK2622    |
|      30044 | UnderSeaWord    |          14 |               80 | SP4533    |
|      98764 | Gold Rush       |          14 |                1 | FR1001    |
+------------+-----------------+-------------+------------------+-----------+
11 rows in set (0.000 sec)

MariaDB [THEME_PARK]> exit
Bye
shafeen@shafeen-Dell-G15-5515 ~> sudo /opt/lampp/bin/mysqldump -u root -p THEME_PARK > /home/shafeen/Desktop/newthemepark_after_changing_attractAGE.sql
Enter password: 
shafeen@shafeen-Dell-G15-5515 ~> sudo /opt/lampp/bin/mysql -u root -p
Enter password: 
Welcome to the MariaDB monitor.  Commands end with ; or \g.
Your MariaDB connection id is 30
Server version: 10.4.32-MariaDB Source distribution

Copyright (c) 2000, 2018, Oracle, MariaDB Corporation Ab and others.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

MariaDB [(none)]> USE THEME_PARK;
Reading table information for completion of table and column names
You can turn off this feature to get a quicker startup with -A

Database changed
MariaDB [THEME_PARK]> SELECT * FROM ATTRACTION;
+------------+-----------------+-------------+------------------+-----------+
| ATTRACT_NO | ATTRACT_NAME    | ATTRACT_AGE | ATTRACT_CAPACITY | PARK_CODE |
+------------+-----------------+-------------+------------------+-----------+
|      10034 | ThunderCoaster  |          14 |               34 | FR1001    |
|      10056 | SpinningTeacups |          14 |               62 | FR1001    |
|      10067 | FlightToStars   |          14 |               24 | SP4533    |
|      10082 | NULL            |          14 |               40 | FR1001    |
|      10098 | Carnival        |          14 |              120 | ZA1342    |
|      18878 | Ant-Trap        |          14 |               30 | ZA1342    |
|      20056 | 3D-Lego_Show    |          14 |              200 | FR1001    |
|      30011 | BlackHole2      |          14 |               34 | UK2622    |
|      30012 | Pirates         |          14 |               42 | UK2622    |
|      30044 | UnderSeaWord    |          14 |               80 | SP4533    |
|      98764 | Gold Rush       |          14 |                1 | FR1001    |
+------------+-----------------+-------------+------------------+-----------+
11 rows in set (0.000 sec)

MariaDB [THEME_PARK]> SELECT * FROM THEMEPARK;
+-----------+----------------+--------------+--------------+
| PARK_CODE | PARK_NAME      | PARK_CITY    | PARK_COUNTRY |
+-----------+----------------+--------------+--------------+
| FR1001    | FairyLand      | PARIS        | FR           |
| NL1202    | Efling         | NOORD        | IN           |
| SP4533    | Adventure Port | BARCELONA    | SP           |
| SW2323    | Labyrinthe     | LAUSANNE     | SV           |
| UK2622    | MiniLand       | WINDSOR      | UK           |
| UK3452    | PleasureLand   | STOKE        | UK           |
| ZA1342    | GoldTown       | JOHANNESBURG | ZA           |
+-----------+----------------+--------------+--------------+
7 rows in set (0.000 sec)

MariaDB [THEME_PARK]> show tables
    -> ;
+----------------------+
| Tables_in_THEME_PARK |
+----------------------+
| ATTRACTION           |
| EMPLOYEE             |
| HOURS                |
| SALES                |
| SALES_LINE           |
| THEMEPARK            |
| TICKET               |
+----------------------+
7 rows in set (0.000 sec)

MariaDB [THEME_PARK]> SELECT * FROM EMPLOYEE;
+---------+-----------+-----------+-----------+------------+---------------+---------------+--------------+-----------+
| EMP_NUM | EMP_TITLE | EMP_LNAME | EMP_FNAME | EMP_DOB    | EMP_HIRE_DATE | EMP_AREA_CODE | EMP_PHONE    | PARK_CODE |
+---------+-----------+-----------+-----------+------------+---------------+---------------+--------------+-----------+
|    1234 | Mr.       | Doe       | John      | 2000-01-01 | 2021-01-01    | 123           | 123-456-7890 | FR1001    |
|    2222 | Miss      | Williams  | Emily     | 1992-08-23 | 2017-06-20    | 321           | 333-444-5555 | NL1202    |
|    3333 | Mr.       | Brown     | Michael   | 1985-04-10 | 2015-12-03    | 555           | 888-777-9999 | FR1001    |
|    4444 | Ms.       | Davis     | Sophia    | 1990-07-07 | 2016-09-25    | 666           | 222-111-3333 | SP4533    |
|    5555 | Dr.       | Lee       | Andrew    | 1978-11-30 | 2014-03-12    | 888           | 444-555-6666 | SW2323    |
|    5678 | Mrs.      | Smith     | Jane      | 1995-05-15 | 2020-02-15    | 456           | 987-654-3210 | NL1202    |
|    6666 | Mrs.      | Taylor    | Olivia    | 1988-02-18 | 2013-07-08    | 999           | 777-888-0000 | UK2622    |
|    7777 | Mr.       | Harris    | David     | 1997-06-05 | 2012-05-22    | 111           | 666-333-9999 | UK3452    |
|    8888 | Miss      | Garcia    | Isabella  | 1983-09-12 | 2011-10-18    | 444           | 999-222-1111 | ZA1342    |
|    9101 | Dr.       | Johnson   | Robert    | 1980-12-05 | 2018-08-10    | 789           | 555-123-4567 | FR1001    |
+---------+-----------+-----------+-----------+------------+---------------+---------------+--------------+-----------+
10 rows in set (0.000 sec)

MariaDB [THEME_PARK]> describe EMPLOYEE;
+---------------+--------------+------+-----+---------+-------+
| Field         | Type         | Null | Key | Default | Extra |
+---------------+--------------+------+-----+---------+-------+
| EMP_NUM       | decimal(4,0) | NO   | PRI | NULL    |       |
| EMP_TITLE     | varchar(4)   | YES  |     | NULL    |       |
| EMP_LNAME     | varchar(15)  | NO   |     | NULL    |       |
| EMP_FNAME     | varchar(15)  | NO   |     | NULL    |       |
| EMP_DOB       | date         | NO   |     | NULL    |       |
| EMP_HIRE_DATE | date         | YES  |     | NULL    |       |
| EMP_AREA_CODE | varchar(4)   | NO   |     | NULL    |       |
| EMP_PHONE     | varchar(12)  | NO   |     | NULL    |       |
| PARK_CODE     | varchar(10)  | YES  | MUL | NULL    |       |
+---------------+--------------+------+-----+---------+-------+
9 rows in set (0.001 sec)

MariaDB [THEME_PARK]> INSERT INTO EMPLOYEE VALUE (2049,'Mr','Rahat','Noman','1990-12-20','2015-5-5','7253,502-4934','UK3452');
ERROR 1136 (21S01): Column count doesn't match value count at row 1
MariaDB [THEME_PARK]> INSERT INTO EMPLOYEE VALUE (2049,'Mr','Rahat','Noman','1990-12-20','2015-5-5','7253',502-4934','UK3452');
    '> ;
    '> SELECT * FROM ATTRACTION;
    '> exit
    '> Ctrl-C -- exit!
Aborted
shafeen@shafeen-Dell-G15-5515 ~ [1]> sudo /opt/lampp/bin/mysql -u root -p
Enter password: 
Welcome to the MariaDB monitor.  Commands end with ; or \g.
Your MariaDB connection id is 31
Server version: 10.4.32-MariaDB Source distribution

Copyright (c) 2000, 2018, Oracle, MariaDB Corporation Ab and others.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

MariaDB [(none)]> USE THEME_PARK;
Reading table information for completion of table and column names
You can turn off this feature to get a quicker startup with -A

Database changed
MariaDB [THEME_PARK]> SELECT * FROM ATTRACTION;
+------------+-----------------+-------------+------------------+-----------+
| ATTRACT_NO | ATTRACT_NAME    | ATTRACT_AGE | ATTRACT_CAPACITY | PARK_CODE |
+------------+-----------------+-------------+------------------+-----------+
|      10034 | ThunderCoaster  |          14 |               34 | FR1001    |
|      10056 | SpinningTeacups |          14 |               62 | FR1001    |
|      10067 | FlightToStars   |          14 |               24 | SP4533    |
|      10082 | NULL            |          14 |               40 | FR1001    |
|      10098 | Carnival        |          14 |              120 | ZA1342    |
|      18878 | Ant-Trap        |          14 |               30 | ZA1342    |
|      20056 | 3D-Lego_Show    |          14 |              200 | FR1001    |
|      30011 | BlackHole2      |          14 |               34 | UK2622    |
|      30012 | Pirates         |          14 |               42 | UK2622    |
|      30044 | UnderSeaWord    |          14 |               80 | SP4533    |
|      98764 | Gold Rush       |          14 |                1 | FR1001    |
+------------+-----------------+-------------+------------------+-----------+
11 rows in set (0.000 sec)

MariaDB [THEME_PARK]> SELECT * FROM EMPLOYEE;
+---------+-----------+-----------+-----------+------------+---------------+---------------+--------------+-----------+
| EMP_NUM | EMP_TITLE | EMP_LNAME | EMP_FNAME | EMP_DOB    | EMP_HIRE_DATE | EMP_AREA_CODE | EMP_PHONE    | PARK_CODE |
+---------+-----------+-----------+-----------+------------+---------------+---------------+--------------+-----------+
|    1234 | Mr.       | Doe       | John      | 2000-01-01 | 2021-01-01    | 123           | 123-456-7890 | FR1001    |
|    2222 | Miss      | Williams  | Emily     | 1992-08-23 | 2017-06-20    | 321           | 333-444-5555 | NL1202    |
|    3333 | Mr.       | Brown     | Michael   | 1985-04-10 | 2015-12-03    | 555           | 888-777-9999 | FR1001    |
|    4444 | Ms.       | Davis     | Sophia    | 1990-07-07 | 2016-09-25    | 666           | 222-111-3333 | SP4533    |
|    5555 | Dr.       | Lee       | Andrew    | 1978-11-30 | 2014-03-12    | 888           | 444-555-6666 | SW2323    |
|    5678 | Mrs.      | Smith     | Jane      | 1995-05-15 | 2020-02-15    | 456           | 987-654-3210 | NL1202    |
|    6666 | Mrs.      | Taylor    | Olivia    | 1988-02-18 | 2013-07-08    | 999           | 777-888-0000 | UK2622    |
|    7777 | Mr.       | Harris    | David     | 1997-06-05 | 2012-05-22    | 111           | 666-333-9999 | UK3452    |
|    8888 | Miss      | Garcia    | Isabella  | 1983-09-12 | 2011-10-18    | 444           | 999-222-1111 | ZA1342    |
|    9101 | Dr.       | Johnson   | Robert    | 1980-12-05 | 2018-08-10    | 789           | 555-123-4567 | FR1001    |
+---------+-----------+-----------+-----------+------------+---------------+---------------+--------------+-----------+
10 rows in set (0.000 sec)

MariaDB [THEME_PARK]> INSERT INTO EMPLOYEE VALUES (2049,'Mr','Rahat','Noman','1990-12-20','2015-5-5','7253','502-493-5555','UK3452');
Query OK, 1 row affected (0.003 sec)

MariaDB [THEME_PARK]> UPDATE EMPLOYEE
    -> SET EMP_FNAME='DAVID';
Query OK, 11 rows affected (0.003 sec)
Rows matched: 11  Changed: 11  Warnings: 0

MariaDB [THEME_PARK]> SELECT * FROM EMPLOYEE;
+---------+-----------+-----------+-----------+------------+---------------+---------------+--------------+-----------+
| EMP_NUM | EMP_TITLE | EMP_LNAME | EMP_FNAME | EMP_DOB    | EMP_HIRE_DATE | EMP_AREA_CODE | EMP_PHONE    | PARK_CODE |
+---------+-----------+-----------+-----------+------------+---------------+---------------+--------------+-----------+
|    1234 | Mr.       | Doe       | DAVID     | 2000-01-01 | 2021-01-01    | 123           | 123-456-7890 | FR1001    |
|    2049 | Mr        | Rahat     | DAVID     | 1990-12-20 | 2015-05-05    | 7253          | 502-493-5555 | UK3452    |
|    2222 | Miss      | Williams  | DAVID     | 1992-08-23 | 2017-06-20    | 321           | 333-444-5555 | NL1202    |
|    3333 | Mr.       | Brown     | DAVID     | 1985-04-10 | 2015-12-03    | 555           | 888-777-9999 | FR1001    |
|    4444 | Ms.       | Davis     | DAVID     | 1990-07-07 | 2016-09-25    | 666           | 222-111-3333 | SP4533    |
|    5555 | Dr.       | Lee       | DAVID     | 1978-11-30 | 2014-03-12    | 888           | 444-555-6666 | SW2323    |
|    5678 | Mrs.      | Smith     | DAVID     | 1995-05-15 | 2020-02-15    | 456           | 987-654-3210 | NL1202    |
|    6666 | Mrs.      | Taylor    | DAVID     | 1988-02-18 | 2013-07-08    | 999           | 777-888-0000 | UK2622    |
|    7777 | Mr.       | Harris    | DAVID     | 1997-06-05 | 2012-05-22    | 111           | 666-333-9999 | UK3452    |
|    8888 | Miss      | Garcia    | DAVID     | 1983-09-12 | 2011-10-18    | 444           | 999-222-1111 | ZA1342    |
|    9101 | Dr.       | Johnson   | DAVID     | 1980-12-05 | 2018-08-10    | 789           | 555-123-4567 | FR1001    |
+---------+-----------+-----------+-----------+------------+---------------+---------------+--------------+-----------+
11 rows in set (0.001 sec)

MariaDB [THEME_PARK]> UPDATE EMPLOTEE
    -> SET EMP_FNAME = 'John'
    -> WHERE EMP_NUM = 1234;
ERROR 1146 (42S02): Table 'THEME_PARK.EMPLOTEE' doesn't exist
MariaDB [THEME_PARK]> UPDATE EMPLOYEE SET EMP_FNAME = 'John' WHERE EMP_NUM = 1234;
Query OK, 1 row affected (0.003 sec)
Rows matched: 1  Changed: 1  Warnings: 0

MariaDB [THEME_PARK]> SELECT * FROM EMPLOYEE;
+---------+-----------+-----------+-----------+------------+---------------+---------------+--------------+-----------+
| EMP_NUM | EMP_TITLE | EMP_LNAME | EMP_FNAME | EMP_DOB    | EMP_HIRE_DATE | EMP_AREA_CODE | EMP_PHONE    | PARK_CODE |
+---------+-----------+-----------+-----------+------------+---------------+---------------+--------------+-----------+
|    1234 | Mr.       | Doe       | John      | 2000-01-01 | 2021-01-01    | 123           | 123-456-7890 | FR1001    |
|    2049 | Mr        | Rahat     | DAVID     | 1990-12-20 | 2015-05-05    | 7253          | 502-493-5555 | UK3452    |
|    2222 | Miss      | Williams  | DAVID     | 1992-08-23 | 2017-06-20    | 321           | 333-444-5555 | NL1202    |
|    3333 | Mr.       | Brown     | DAVID     | 1985-04-10 | 2015-12-03    | 555           | 888-777-9999 | FR1001    |
|    4444 | Ms.       | Davis     | DAVID     | 1990-07-07 | 2016-09-25    | 666           | 222-111-3333 | SP4533    |
|    5555 | Dr.       | Lee       | DAVID     | 1978-11-30 | 2014-03-12    | 888           | 444-555-6666 | SW2323    |
|    5678 | Mrs.      | Smith     | DAVID     | 1995-05-15 | 2020-02-15    | 456           | 987-654-3210 | NL1202    |
|    6666 | Mrs.      | Taylor    | DAVID     | 1988-02-18 | 2013-07-08    | 999           | 777-888-0000 | UK2622    |
|    7777 | Mr.       | Harris    | DAVID     | 1997-06-05 | 2012-05-22    | 111           | 666-333-9999 | UK3452    |
|    8888 | Miss      | Garcia    | DAVID     | 1983-09-12 | 2011-10-18    | 444           | 999-222-1111 | ZA1342    |
|    9101 | Dr.       | Johnson   | DAVID     | 1980-12-05 | 2018-08-10    | 789           | 555-123-4567 | FR1001    |
+---------+-----------+-----------+-----------+------------+---------------+---------------+--------------+-----------+
11 rows in set (0.000 sec)

MariaDB [THEME_PARK]> Ctrl-C -- exit!
Aborted
shafeen@shafeen-Dell-G15-5515 ~ [1]> sudo /opt/lampp/bin/mysql -u root -p
Enter password: 
Welcome to the MariaDB monitor.  Commands end with ; or \g.
Your MariaDB connection id is 32
Server version: 10.4.32-MariaDB Source distribution

Copyright (c) 2000, 2018, Oracle, MariaDB Corporation Ab and others.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

MariaDB [(none)]> USE THEME_PARK
Reading table information for completion of table and column names
You can turn off this feature to get a quicker startup with -A

Database changed
MariaDB [THEME_PARK]> SELECT * FROM ATTRACTION;
+------------+-----------------+-------------+------------------+-----------+
| ATTRACT_NO | ATTRACT_NAME    | ATTRACT_AGE | ATTRACT_CAPACITY | PARK_CODE |
+------------+-----------------+-------------+------------------+-----------+
|      10034 | ThunderCoaster  |          14 |               34 | FR1001    |
|      10056 | SpinningTeacups |          14 |               62 | FR1001    |
|      10067 | FlightToStars   |          14 |               24 | SP4533    |
|      10082 | NULL            |          14 |               40 | FR1001    |
|      10098 | Carnival        |          14 |              120 | ZA1342    |
|      18878 | Ant-Trap        |          14 |               30 | ZA1342    |
|      20056 | 3D-Lego_Show    |          14 |              200 | FR1001    |
|      30011 | BlackHole2      |          14 |               34 | UK2622    |
|      30012 | Pirates         |          14 |               42 | UK2622    |
|      30044 | UnderSeaWord    |          14 |               80 | SP4533    |
|      98764 | Gold Rush       |          14 |                1 | FR1001    |
+------------+-----------------+-------------+------------------+-----------+
11 rows in set (0.000 sec)

MariaDB [THEME_PARK]> SELECT * FROM EMPLOYEE
    -> ;
+---------+-----------+-----------+-----------+------------+---------------+---------------+--------------+-----------+
| EMP_NUM | EMP_TITLE | EMP_LNAME | EMP_FNAME | EMP_DOB    | EMP_HIRE_DATE | EMP_AREA_CODE | EMP_PHONE    | PARK_CODE |
+---------+-----------+-----------+-----------+------------+---------------+---------------+--------------+-----------+
|    1234 | Mr.       | Doe       | John      | 2000-01-01 | 2021-01-01    | 123           | 123-456-7890 | FR1001    |
|    2049 | Mr        | Rahat     | DAVID     | 1990-12-20 | 2015-05-05    | 7253          | 502-493-5555 | UK3452    |
|    2222 | Miss      | Williams  | DAVID     | 1992-08-23 | 2017-06-20    | 321           | 333-444-5555 | NL1202    |
|    3333 | Mr.       | Brown     | DAVID     | 1985-04-10 | 2015-12-03    | 555           | 888-777-9999 | FR1001    |
|    4444 | Ms.       | Davis     | DAVID     | 1990-07-07 | 2016-09-25    | 666           | 222-111-3333 | SP4533    |
|    5555 | Dr.       | Lee       | DAVID     | 1978-11-30 | 2014-03-12    | 888           | 444-555-6666 | SW2323    |
|    5678 | Mrs.      | Smith     | DAVID     | 1995-05-15 | 2020-02-15    | 456           | 987-654-3210 | NL1202    |
|    6666 | Mrs.      | Taylor    | DAVID     | 1988-02-18 | 2013-07-08    | 999           | 777-888-0000 | UK2622    |
|    7777 | Mr.       | Harris    | DAVID     | 1997-06-05 | 2012-05-22    | 111           | 666-333-9999 | UK3452    |
|    8888 | Miss      | Garcia    | DAVID     | 1983-09-12 | 2011-10-18    | 444           | 999-222-1111 | ZA1342    |
|    9101 | Dr.       | Johnson   | DAVID     | 1980-12-05 | 2018-08-10    | 789           | 555-123-4567 | FR1001    |
+---------+-----------+-----------+-----------+------------+---------------+---------------+--------------+-----------+
11 rows in set (0.000 sec)

MariaDB [THEME_PARK]> UPDATE EMPLOYEE
    -> SET EMP_FNAME = 'John'
    -> WHERE EMP_NUM = 1234;
Query OK, 0 rows affected (0.000 sec)
Rows matched: 1  Changed: 0  Warnings: 0

MariaDB [THEME_PARK]> 
MariaDB [THEME_PARK]> UPDATE EMPLOYEE
    -> SET EMP_FNAME = 'Emily'
    -> WHERE EMP_NUM = 2222;
Query OK, 1 row affected (0.002 sec)
Rows matched: 1  Changed: 1  Warnings: 0

MariaDB [THEME_PARK]> 
MariaDB [THEME_PARK]> UPDATE EMPLOYEE
    -> SET EMP_FNAME = 'Michael'
    -> WHERE EMP_NUM = 3333;
Query OK, 1 row affected (0.002 sec)
Rows matched: 1  Changed: 1  Warnings: 0

MariaDB [THEME_PARK]> 
MariaDB [THEME_PARK]> UPDATE EMPLOYEE
    -> SET EMP_FNAME = 'Sophia'
    -> WHERE EMP_NUM = 4444;
Query OK, 1 row affected (0.001 sec)
Rows matched: 1  Changed: 1  Warnings: 0

MariaDB [THEME_PARK]> 
MariaDB [THEME_PARK]> UPDATE EMPLOYEE
    -> SET EMP_FNAME = 'Andrew'
    -> WHERE EMP_NUM = 5555;
Query OK, 1 row affected (0.002 sec)
Rows matched: 1  Changed: 1  Warnings: 0

MariaDB [THEME_PARK]> 
MariaDB [THEME_PARK]> UPDATE EMPLOYEE
    -> SET EMP_FNAME = 'Jane'
    -> WHERE EMP_NUM = 5678;
Query OK, 1 row affected (0.002 sec)
Rows matched: 1  Changed: 1  Warnings: 0

MariaDB [THEME_PARK]> 
MariaDB [THEME_PARK]> UPDATE EMPLOYEE
    -> SET EMP_FNAME = 'Olivia'
    -> WHERE EMP_NUM = 6666;
Query OK, 1 row affected (0.002 sec)
Rows matched: 1  Changed: 1  Warnings: 0

MariaDB [THEME_PARK]> 
MariaDB [THEME_PARK]> UPDATE EMPLOYEE
    -> SET EMP_FNAME = 'David'
    -> WHERE EMP_NUM = 7777;
Query OK, 1 row affected (0.001 sec)
Rows matched: 1  Changed: 1  Warnings: 0

MariaDB [THEME_PARK]> 
MariaDB [THEME_PARK]> UPDATE EMPLOYEE
    -> SET EMP_FNAME = 'Isabella'
    -> WHERE EMP_NUM = 8888;
Query OK, 1 row affected (0.002 sec)
Rows matched: 1  Changed: 1  Warnings: 0

MariaDB [THEME_PARK]> 
MariaDB [THEME_PARK]> UPDATE EMPLOYEE
    -> SET EMP_FNAME = 'Robert'
    -> WHERE EMP_NUM = 9101;
Query OK, 1 row affected (0.003 sec)
Rows matched: 1  Changed: 1  Warnings: 0

MariaDB [THEME_PARK]> SELECT * FROM EMPLOYEE;
+---------+-----------+-----------+-----------+------------+---------------+---------------+--------------+-----------+
| EMP_NUM | EMP_TITLE | EMP_LNAME | EMP_FNAME | EMP_DOB    | EMP_HIRE_DATE | EMP_AREA_CODE | EMP_PHONE    | PARK_CODE |
+---------+-----------+-----------+-----------+------------+---------------+---------------+--------------+-----------+
|    1234 | Mr.       | Doe       | John      | 2000-01-01 | 2021-01-01    | 123           | 123-456-7890 | FR1001    |
|    2049 | Mr        | Rahat     | DAVID     | 1990-12-20 | 2015-05-05    | 7253          | 502-493-5555 | UK3452    |
|    2222 | Miss      | Williams  | Emily     | 1992-08-23 | 2017-06-20    | 321           | 333-444-5555 | NL1202    |
|    3333 | Mr.       | Brown     | Michael   | 1985-04-10 | 2015-12-03    | 555           | 888-777-9999 | FR1001    |
|    4444 | Ms.       | Davis     | Sophia    | 1990-07-07 | 2016-09-25    | 666           | 222-111-3333 | SP4533    |
|    5555 | Dr.       | Lee       | Andrew    | 1978-11-30 | 2014-03-12    | 888           | 444-555-6666 | SW2323    |
|    5678 | Mrs.      | Smith     | Jane      | 1995-05-15 | 2020-02-15    | 456           | 987-654-3210 | NL1202    |
|    6666 | Mrs.      | Taylor    | Olivia    | 1988-02-18 | 2013-07-08    | 999           | 777-888-0000 | UK2622    |
|    7777 | Mr.       | Harris    | David     | 1997-06-05 | 2012-05-22    | 111           | 666-333-9999 | UK3452    |
|    8888 | Miss      | Garcia    | Isabella  | 1983-09-12 | 2011-10-18    | 444           | 999-222-1111 | ZA1342    |
|    9101 | Dr.       | Johnson   | Robert    | 1980-12-05 | 2018-08-10    | 789           | 555-123-4567 | FR1001    |
+---------+-----------+-----------+-----------+------------+---------------+---------------+--------------+-----------+
11 rows in set (0.000 sec)

MariaDB [THEME_PARK]> UPDATE EMPLOYEE
    -> SET EMP_FNAME = 'DAVID'
    -> WHERE EMP_NUM = 9101;
Query OK, 1 row affected (0.003 sec)
Rows matched: 1  Changed: 1  Warnings: 0

MariaDB [THEME_PARK]> SELECT * FROM EMPLOYEE;
+---------+-----------+-----------+-----------+------------+---------------+---------------+--------------+-----------+
| EMP_NUM | EMP_TITLE | EMP_LNAME | EMP_FNAME | EMP_DOB    | EMP_HIRE_DATE | EMP_AREA_CODE | EMP_PHONE    | PARK_CODE |
+---------+-----------+-----------+-----------+------------+---------------+---------------+--------------+-----------+
|    1234 | Mr.       | Doe       | John      | 2000-01-01 | 2021-01-01    | 123           | 123-456-7890 | FR1001    |
|    2049 | Mr        | Rahat     | DAVID     | 1990-12-20 | 2015-05-05    | 7253          | 502-493-5555 | UK3452    |
|    2222 | Miss      | Williams  | Emily     | 1992-08-23 | 2017-06-20    | 321           | 333-444-5555 | NL1202    |
|    3333 | Mr.       | Brown     | Michael   | 1985-04-10 | 2015-12-03    | 555           | 888-777-9999 | FR1001    |
|    4444 | Ms.       | Davis     | Sophia    | 1990-07-07 | 2016-09-25    | 666           | 222-111-3333 | SP4533    |
|    5555 | Dr.       | Lee       | Andrew    | 1978-11-30 | 2014-03-12    | 888           | 444-555-6666 | SW2323    |
|    5678 | Mrs.      | Smith     | Jane      | 1995-05-15 | 2020-02-15    | 456           | 987-654-3210 | NL1202    |
|    6666 | Mrs.      | Taylor    | Olivia    | 1988-02-18 | 2013-07-08    | 999           | 777-888-0000 | UK2622    |
|    7777 | Mr.       | Harris    | David     | 1997-06-05 | 2012-05-22    | 111           | 666-333-9999 | UK3452    |
|    8888 | Miss      | Garcia    | Isabella  | 1983-09-12 | 2011-10-18    | 444           | 999-222-1111 | ZA1342    |
|    9101 | Dr.       | Johnson   | DAVID     | 1980-12-05 | 2018-08-10    | 789           | 555-123-4567 | FR1001    |
+---------+-----------+-----------+-----------+------------+---------------+---------------+--------------+-----------+
11 rows in set (0.001 sec)

MariaDB [THEME_PARK]> exit
Bye
shafeen@shafeen-Dell-G15-5515 ~> sudo /opt/lampp/bin/mysqldump -u root -p THEME_PARK > /home/shafeen/Desktop/newthemepark_after_changing_Names.sql
Enter password: 
shafeen@shafeen-Dell-G15-5515 ~> sudo /opt/lampp/bin/mysql -u root -p
Enter password: 
Welcome to the MariaDB monitor.  Commands end with ; or \g.
Your MariaDB connection id is 34
Server version: 10.4.32-MariaDB Source distribution

Copyright (c) 2000, 2018, Oracle, MariaDB Corporation Ab and others.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

MariaDB [(none)]> USE THEME_PARK;
Reading table information for completion of table and column names
You can turn off this feature to get a quicker startup with -A

Database changed
MariaDB [THEME_PARK]> SELECT * FROM EMPLOYEE;
+---------+-----------+-----------+-----------+------------+---------------+---------------+--------------+-----------+
| EMP_NUM | EMP_TITLE | EMP_LNAME | EMP_FNAME | EMP_DOB    | EMP_HIRE_DATE | EMP_AREA_CODE | EMP_PHONE    | PARK_CODE |
+---------+-----------+-----------+-----------+------------+---------------+---------------+--------------+-----------+
|    1234 | Mr.       | Doe       | John      | 2000-01-01 | 2021-01-01    | 123           | 123-456-7890 | FR1001    |
|    2049 | Mr        | Rahat     | DAVID     | 1990-12-20 | 2015-05-05    | 7253          | 502-493-5555 | UK3452    |
|    2222 | Miss      | Williams  | Emily     | 1992-08-23 | 2017-06-20    | 321           | 333-444-5555 | NL1202    |
|    3333 | Mr.       | Brown     | Michael   | 1985-04-10 | 2015-12-03    | 555           | 888-777-9999 | FR1001    |
|    4444 | Ms.       | Davis     | Sophia    | 1990-07-07 | 2016-09-25    | 666           | 222-111-3333 | SP4533    |
|    5555 | Dr.       | Lee       | Andrew    | 1978-11-30 | 2014-03-12    | 888           | 444-555-6666 | SW2323    |
|    5678 | Mrs.      | Smith     | Jane      | 1995-05-15 | 2020-02-15    | 456           | 987-654-3210 | NL1202    |
|    6666 | Mrs.      | Taylor    | Olivia    | 1988-02-18 | 2013-07-08    | 999           | 777-888-0000 | UK2622    |
|    7777 | Mr.       | Harris    | David     | 1997-06-05 | 2012-05-22    | 111           | 666-333-9999 | UK3452    |
|    8888 | Miss      | Garcia    | Isabella  | 1983-09-12 | 2011-10-18    | 444           | 999-222-1111 | ZA1342    |
|    9101 | Dr.       | Johnson   | DAVID     | 1980-12-05 | 2018-08-10    | 789           | 555-123-4567 | FR1001    |
+---------+-----------+-----------+-----------+------------+---------------+---------------+--------------+-----------+
11 rows in set (0.000 sec)

MariaDB [THEME_PARK]> SELECT * FROM THEMEPARK;
+-----------+----------------+--------------+--------------+
| PARK_CODE | PARK_NAME      | PARK_CITY    | PARK_COUNTRY |
+-----------+----------------+--------------+--------------+
| FR1001    | FairyLand      | PARIS        | FR           |
| NL1202    | Efling         | NOORD        | IN           |
| SP4533    | Adventure Port | BARCELONA    | SP           |
| SW2323    | Labyrinthe     | LAUSANNE     | SV           |
| UK2622    | MiniLand       | WINDSOR      | UK           |
| UK3452    | PleasureLand   | STOKE        | UK           |
| ZA1342    | GoldTown       | JOHANNESBURG | ZA           |
+-----------+----------------+--------------+--------------+
7 rows in set (0.000 sec)

MariaDB [THEME_PARK]> INSERT THEMEPARK INTO VALUE ( 'PK2049
    '> '
    -> exit
    -> ''
    -> '
    '> Ctrl-C -- exit!
Aborted
shafeen@shafeen-Dell-G15-5515 ~ [1]> sudo /opt/lampp/bin/mysql -u root -p
Enter password: 
Welcome to the MariaDB monitor.  Commands end with ; or \g.
Your MariaDB connection id is 35
Server version: 10.4.32-MariaDB Source distribution

Copyright (c) 2000, 2018, Oracle, MariaDB Corporation Ab and others.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

MariaDB [(none)]> USE THEME_PARK;
Reading table information for completion of table and column names
You can turn off this feature to get a quicker startup with -A

Database changed
MariaDB [THEME_PARK]> SELECT * FROM THEMEPARK;
+-----------+----------------+--------------+--------------+
| PARK_CODE | PARK_NAME      | PARK_CITY    | PARK_COUNTRY |
+-----------+----------------+--------------+--------------+
| FR1001    | FairyLand      | PARIS        | FR           |
| NL1202    | Efling         | NOORD        | IN           |
| SP4533    | Adventure Port | BARCELONA    | SP           |
| SW2323    | Labyrinthe     | LAUSANNE     | SV           |
| UK2622    | MiniLand       | WINDSOR      | UK           |
| UK3452    | PleasureLand   | STOKE        | UK           |
| ZA1342    | GoldTown       | JOHANNESBURG | ZA           |
+-----------+----------------+--------------+--------------+
7 rows in set (0.000 sec)

MariaDB [THEME_PARK]> INSERT INTO THEMEPARK VALUES ('PK2049', 'Garrison', 'Peshawar', 'PK');
Query OK, 1 row affected (0.003 sec)

MariaDB [THEME_PARK]> SELECT * FROM THEMEPARK;
+-----------+----------------+--------------+--------------+
| PARK_CODE | PARK_NAME      | PARK_CITY    | PARK_COUNTRY |
+-----------+----------------+--------------+--------------+
| FR1001    | FairyLand      | PARIS        | FR           |
| NL1202    | Efling         | NOORD        | IN           |
| PK2049    | Garrison       | Peshawar     | PK           |
| SP4533    | Adventure Port | BARCELONA    | SP           |
| SW2323    | Labyrinthe     | LAUSANNE     | SV           |
| UK2622    | MiniLand       | WINDSOR      | UK           |
| UK3452    | PleasureLand   | STOKE        | UK           |
| ZA1342    | GoldTown       | JOHANNESBURG | ZA           |
+-----------+----------------+--------------+--------------+
8 rows in set (0.000 sec)

MariaDB [THEME_PARK]> DELETE FROM THEMEPARK
    -> WHERE PARK_CODE='PK2049';
Query OK, 1 row affected (0.003 sec)

MariaDB [THEME_PARK]> SELECT * FROM THEMEPARK;
+-----------+----------------+--------------+--------------+
| PARK_CODE | PARK_NAME      | PARK_CITY    | PARK_COUNTRY |
+-----------+----------------+--------------+--------------+
| FR1001    | FairyLand      | PARIS        | FR           |
| NL1202    | Efling         | NOORD        | IN           |
| SP4533    | Adventure Port | BARCELONA    | SP           |
| SW2323    | Labyrinthe     | LAUSANNE     | SV           |
| UK2622    | MiniLand       | WINDSOR      | UK           |
| UK3452    | PleasureLand   | STOKE        | UK           |
| ZA1342    | GoldTown       | JOHANNESBURG | ZA           |
+-----------+----------------+--------------+--------------+
7 rows in set (0.000 sec)

MariaDB [THEME_PARK]> Ctrl-C -- exit!
Aborted
shafeen@shafeen-Dell-G15-5515 ~ [1]> sudo /opt/lampp/bin/mysqldump -u root -p THEME_PARK > /home/shafeen/Desktop/newthemepark_after_deletion.sql
Enter password: 
shafeen@shafeen-Dell-G15-5515 ~> 
