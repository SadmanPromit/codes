CREATE TABLE Employees(
Employee_Id NUMERIC(6) PRIMARY KEY,
First_Name VARCHAR(20),
Last_Name VARCHAR(25) NOT NULL,
Email VARCHAR(25) NOT NULL,
Phone_Number VARCHAR(15),
Hire_Date DATE NOT NULL,
Job_Id VARCHAR(10) NOT NULL,
Salary NUMERIC(8,2),
Commission_PCT NUMERIC(2,2),
Manager_id NUMERIC(6),
Department_Id NUMERIC(4));


INSERT INTO Employees VALUES (100, 'Steven','King', 'SKING','515.123.4567', STR_TO_DATE('JUN-17-2006','%b-%d-%Y'), 'AD_PRESS',24000, NULL, NULL, 90),
(101, 'Neena','Kochar', 'NKOCHAR','515.123.4568', STR_TO_DATE('SEP-21-2008','%b-%d-%Y'), 'AD_VP',17000, NULL, 100, 90),
(102, 'Lex','De Haan', 'DEHAAN','515.123.4569', STR_TO_DATE('JAN-13-2009','%b-%d-%Y'), 'AD_VP',17000, NULL, 100, 90),
(103, 'Alexander','Hunold', 'AHUNOLD','590.423.4567', STR_TO_DATE('JAN-03-2008','%b-%d-%Y'), 'IT_PROG',9000,NULL, 102, 60),
(104, 'Bruce','Ernst', 'BERNST','590.423.4568', STR_TO_DATE('MAY-21-2009','%b-%d-%Y'), 'IT_PROG',6000,NULL, 103, 60),
(107, 'Diana','Lorentz', 'DLORENTZ','590.423.5567', STR_TO_DATE('FEB-07-2008','%b-%d-%Y'), 'IT_PROG',4200,NULL, 103, 60),
(124, 'Kevin','Mourgos', 'KMORGOS','650.123.5234', STR_TO_DATE('NOV-16-2012','%b-%d-%Y'), 'ST_MAN',5800,NULL, 100, 50),
(141, 'Treena','Rajs', 'RRAJS','650.121.5234', STR_TO_DATE('OCT-17-2004','%b-%d-%Y'), 'ST_CLERK',3500,NULL, 124, 50),
(142, 'Curtis','Davies', 'CDAVIES','121.123.5234', STR_TO_DATE('JAN-29-2007','%b-%d-%Y'), 'ST_CLERK',3100,NULL, 124, 50),
(143, 'Randall','Matos', 'RMATOS','121.123.5234', STR_TO_DATE('MAR-15-2008','%b-%d-%Y'), 'ST_CLERK',2600,NULL, 124, 50),
(144, 'Peter','Vargas', 'PVARGAS','121.123.5234', STR_TO_DATE('JUL-09-2008','%b-%d-%Y'), 'ST_CLERK',2500,NULL, 124, 50),
(149, 'Eleni','Zlotkey', 'EZLOTKEY','44.1344.429018', STR_TO_DATE('JAN-29-2014','%b-%d-%Y'), 'SA_MAN',10500,.2, 100, 80),
(174, 'Ellen','Abel', 'EABEL','44.1644.429017', STR_TO_DATE('MAY-11-2004','%b-%d-%Y'), 'SA_REP',11000,.3, 149, 80),
(176, 'Jnathon','Taylor', 'JTAILOR','44.1644.429021', STR_TO_DATE('MAR-24-2008','%b-%d-%Y'), 'SA_MAN',8600,.2, 149, 80),
(178, 'Kimberely','Grant', 'KGRANT','44.1644.429023', STR_TO_DATE('MAY-24-2009','%b-%d-%Y'), 'SA_MAN',7000,.15, 149, NULL),
(200, 'Jennifer','Whalem', 'JWHALEN','515.123.4444', STR_TO_DATE('SEP-17-2003','%b-%d-%Y'), 'ADD_ASST',4400,NULL, 101, 10),
(201, 'Michael','Hartstein', 'MHARSTEIN','515.123.5555', STR_TO_DATE('FEB-17-2008','%b-%d-%Y'), 'MK_MAN',13000,NULL, 100, 20),
(202, 'Pat','Fay','PFAY','603.123.6666', STR_TO_DATE('AUG-17-2010','%b-%d-%Y'), 'MK_REP',6000,NULL, 201, 20),
(205, 'Shelley','Higgins', 'SHIGGINS','515.123.8050', STR_TO_DATE('JUN-07-2007','%b-%d-%Y'), 'AC_MGR',12000,NULL, 101, 110),
(206, 'William','Gietz', 'WGIETZ','515.123.8181', STR_TO_DATE('JUN-07-2007','%b-%d-%Y'), 'AC_ACCOUNT',8300,NULL, 205, 110);

CREATE TABLE Departments(
Department_id NUMERIC(4) PRIMARY KEY,
Department_Name VARCHAR(30) NOT NULL,
Manager_id NUMERIC(6),
Location_id NUMERIC(4));

INSERT INTO Departments VALUES(10, 'Administration',200,1700),
(20, 'Marketing',201,1800),
(50, 'Shipping',124,1500),
(60, 'IT',103,1400),
(80, 'Sales',149,2500),
(90, 'Executive',100,1700),
(110, 'Accounting',205,1700),
(190, 'Contracting',NULL,1700);


CREATE TABLE Locations(
Location_id NUMERIC(4) PRIMARY KEY,
Street_Address VARCHAR(40),
Postal_Code VARCHAR(12),
City VARCHAR(30) NOT NULL,
State_Province VARCHAR(25),
Country_ID CHAR(2));


INSERT INTO Locations VALUES(1400, '2014 Jabberwocky Rd','26192','Southlake', 'Texas', 'US'),
(1500, '2011 Interiors Blvd','99236','South San Francisco', 'California', 'US'),
(1700, '2004 Charade Rd','98199', 'Seattle','Washington', 'US'),
(1800, '460 Bloor St. W.','ON M5S 1X8', 'Toronto','Ontario', 'CA'),
(2500, 'Magdalen Centre- The Oxford Sc. Park','OX9 9ZB', 'OXford','Oxford', 'UK');

