/*    CREATION OF SQLITE3 DATABASE      */
-----------------------------------------
sqlite3 mydb;

sqlite> .databases
main: /home/ratan/mydb r/w
sqlite> .databases;

CREATE TABLE Employeeloyee (
  EmployeeNO NUMBER(4) NOT NULL,
  ENAME VARCHAR2(10), 
  JOB VARCHAR2(9), 
  MGR NUMBER(4), 
  HIREDATE DATE, 
  SAL NUMBER(7, 2), 
  COMM NUMBER(7, 2), 
  DEPTNO NUMBER(2)
);


INSERT INTO Employee VALUES (7369, 'SMITH', 'CLERK', 7902, '17-MAR-1980',  800, NULL, 20);
INSERT INTO Employee VALUES (7499, 'ALLEN', 'SALESMAN', 7698, '20-MAR-1981', 1600,  300, 30);
INSERT INTO Employee VALUES (7521, 'WARD', 'SALESMAN', 7698,'22-MAR-1981', 1250,  500, 30);
INSERT INTO Employee VALUES (7566, 'JONES', 'MANAGER', 7839, '2-MAR-1981', 2975, NULL, 20);
INSERT INTO Employee VALUES (7654, 'MARTIN', 'SALESMAN', 7698, '28-MAR-1981', 1250, 1400, 30);
INSERT INTO Employee VALUES (7698, 'BLAKE',  'MANAGER',  7839, '1-MAR-1981', 2850, NULL, 30);
INSERT INTO Employee VALUES (7782, 'CLARK',  'MANAGER', 7839, '9-MAR-1981', 2450, NULL, 10);
INSERT INTO Employee VALUES (7788, 'SCOTT',  'ANALYST', 7566, '09-MAR-1982', 3000, NULL, 20);
INSERT INTO Employee VALUES (7839, 'KING',  'PRESIDENT', NULL, '17-MAR-1981', 5000, NULL, 10);
INSERT INTO Employee VALUES (7844, 'TURNER', 'SALESMAN',  7698,'8-MAR-1981',  1500,    0, 30);
INSERT INTO Employee VALUES (7876, 'ADAMS',  'CLERK', 7788, '12-MAR-1983', 1100, NULL, 20);
INSERT INTO Employee VALUES (7900, 'JAMES',  'CLERK', 7698, '3-MAR-1981',  950, NULL, 30);
INSERT INTO Employee VALUES (7902, 'FORD',   'ANALYST', 7566,'3-MAR-1981', 3000, NULL, 20);
INSERT INTO Employee VALUES (7934, 'MILLER', 'CLERK', 7782, '23-MAR-1982', 1300, NULL, 10);

CREATE TABLE DEPT (
  DEPTNO NUMBER(2), 
  DNAME VARCHAR2(14), 
  LOC VARCHAR2(13)
);

INSERT INTO DEPT VALUES (10, 'ACCOUNTING', 'NEW YORK');
INSERT INTO DEPT VALUES (20, 'RESEARCH',   'DALLAS');
INSERT INTO DEPT VALUES (30, 'SALES',      'CHICAGO');
INSERT INTO DEPT VALUES (40, 'OPERATIONS', 'BOSTON');

CREATE TABLE SALGRADE (
  GRADE NUMBER, LOSAL NUMBER, HISAL NUMBER
);

INSERT INTO SALGRADE VALUES (1,  700, 1200);
INSERT INTO SALGRADE VALUES (2, 1201, 1400);
INSERT INTO SALGRADE VALUES (3, 1401, 2000);
INSERT INTO SALGRADE VALUES (4, 2001, 3000);
INSERT INTO SALGRADE VALUES (5, 3001, 9999);

----------------------
sqlite> .header on
sqlite> .mode column

sqlite> 
sqlite> SELECT * FROM Employee
   ...> ;
EMPNO  ENAME   JOB        MGR   HIREDATE     SAL   COMM  DEPTNO
-----  ------  ---------  ----  -----------  ----  ----  ------
7369   SMITH   CLERK      7902  17-MAR-1980  800         20    
7499   ALLEN   SALESMAN   7698  20-MAR-1981  1600  300   30    
7521   WARD    SALESMAN   7698  22-MAR-1981  1250  500   30    
7566   JONES   MANAGER    7839  2-MAR-1981   2975        20    
7654   MARTIN  SALESMAN   7698  28-MAR-1981  1250  1400  30    
7698   BLAKE   MANAGER    7839  1-MAR-1981   2850        30    
7782   CLARK   MANAGER    7839  9-MAR-1981   2450        10    
7788   SCOTT   ANALYST    7566  09-MAR-1982  3000        20    
7839   KING    PRESIDENT        17-MAR-1981  5000        10    
7844   TURNER  SALESMAN   7698  8-MAR-1981   1500  0     30    
7876   ADAMS   CLERK      7788  12-MAR-1983  1100        20    
7900   JAMES   CLERK      7698  3-MAR-1981   950         30    
7902   FORD    ANALYST    7566  3-MAR-1981   3000        20    
7934   MILLER  CLERK      7782  23-MAR-1982  1300        10   
 
sqlite> SELECT * FROM Dept;
DEPTNO  DNAME       LOC     
------  ----------  --------
10      ACCOUNTING  NEW YORK
20      RESEARCH    DALLAS  
30      SALES       CHICAGO 
40      OPERATIONS  BOSTON  

sqlite> 
sqlite> SELECT * FROM Salgrade;
GRADE  LOSAL  HISAL
-----  -----  -----
1      700    1200 
2      1201   1400 
3      1401   2000 
4      2001   3000 
5      3001   9999 


SELECT e.empno, e.ename, e.job, e.sal, e.deptno, d.dname, d.loc 
FROM Employee e 
INNER JOIN Dept d
ON e.deptno = d.deptno;

--INNER JOIN
SELECT e.empno, e.ename, e.job, e.sal, e.deptno, d.dname, d.loc 
FROM Employee e 
INNER JOIN Dept d
ON e.deptno = d.deptno;

--LEFT OUTER JOIN
SELECT e.empno, e.ename, e.job, e.sal, e.deptno, d.dname, d.loc 
FROM Employee e 
LEFT OUTER JOIN Dept d
ON e.deptno = d.deptno
WHERE d.deptno IS NOT NULL;

--RIGHT OUTER JOIN
SELECT e.empno, e.ename, e.job, e.sal, e.deptno, d.dname, d.loc 
FROM Employee e 
RIGHT OUTER JOIN Dept d
ON e.deptno = d.deptno
WHERE e.deptno IS NOT NULL;

--OUTER JOIN
SELECT e.empno, e.ename, e.job, e.sal, e.deptno, d.dname, d.loc 
FROM Employee e 
FULL OUTER JOIN Dept d
ON e.deptno = d.deptno;

--DISPLAY THE dUPLICATE RECORDS FROM Employee TABLE
SELECT empno, ename, count(*) 
FROM Employee 
GROUP BY empno, ename
HAVING COUNT(*) > 1; 

--GETTING SECOND HIGHEST SALARY FROM Employee
SELECT * FROM Employee
ORDER BY SAL DESC LIMIT 1,1;

--MYSQL
SELECT * FROM Employee ORDER BY salary DESC LIMIT 2,1;

--GENERIC QUERY (Should be ANSWERED)
SELECT * FROM Employee WHERE SAL = (
SELECT MAX(SAL) FROM Employee
WHERE SAL < (SELECT MAX(SAL) FROM Employee));

--Getting nth highest salary from an Employee
sqlite> SELECT * FROM Employee WHERE sal = (
SELECT DISTINCT(sal)
FROM Employee ORDER BY sal DESC LIMIT 3,1);

EMPNO  ENAME  JOB      MGR   HIREDATE    SAL   COMM  DEPTNO
-----  -----  -------  ----  ----------  ----  ----  ------
7698   BLAKE  MANAGER  7839  1-MAR-1981  2850        30
sqlite> 

SELECT DISTINCT TOP 4 sal
FROM Employee ORDER BY sal DESC;
--

SELECT e.ename, m.ename, e.deptno, d.dname, d.loc
FROM Employee e
INNER JOIN Employee m ON e.mgr = m.empno
RIGHT OUTER JOIN Dept d ON e.deptno = d.deptno
WHERE e.ename IS NOT NULL
ORDER BY e.deptno;

ENAME   ENAME  DEPTNO  DNAME       LOC     
------  -----  ------  ----------  --------
                       OPERATIONS  BOSTON
CLARK   KING   10      ACCOUNTING  NEW YORK
MILLER  CLARK  10      ACCOUNTING  NEW YORK
SMITH   FORD   20      RESEARCH    DALLAS
JONES   KING   20      RESEARCH    DALLAS
SCOTT   JONES  20      RESEARCH    DALLAS
ADAMS   SCOTT  20      RESEARCH    DALLAS
FORD    JONES  20      RESEARCH    DALLAS
ALLEN   BLAKE  30      SALES       CHICAGO
WARD    BLAKE  30      SALES       CHICAGO
MARTIN  BLAKE  30      SALES       CHICAGO
BLAKE   KING   30      SALES       CHICAGO
TURNER  BLAKE  30      SALES       CHICAGO
JAMES   BLAKE  30      SALES       CHICAGO
sqlite> 

-- INTERVIEW_QUESTIONS --
/* Getting Number of employees, Average salary, Dept wise from Employee & Dept table. */

sqlite> SELECT d.DNAME, d.DEPTNO, COUNT(*) AS NO_OF_EMP, AVG(SAL) FROM Employee e
RIGHT OUTER JOIN Dept d
ON e.deptno = d.deptno
WHERE e.deptno IS NOT NULL
GROUP BY d.DNAME, d.DEPTNO;

DNAME       DEPTNO  NO_OF_EMP  AVG(SAL)        
----------  ------  ---------  ----------------
ACCOUNTING  10      3          2916.66666666667
RESEARCH    20      5          2175.0          
SALES       30      6          1566.66666666667

----------------------------------------------------------

EMPNO  ENAME   JOB        MGR   HIREDATE     SAL   COMM  DEPTNO
-----  ------  ---------  ----  -----------  ----  ----  ------

sqlite>
SELECT
  r.dname,
  r.deptno,
  r.NO_OF_EMP,
  e.ename,
  e.job,
  e.sal
FROM
  employee e
  INNER JOIN (
    SELECT
      d.DNAME as dname,
      d.DEPTNO as deptno,
      COUNT(*) AS NO_OF_EMP,
      MAX(SAL) AS max_sal
    FROM
      Employee e
      INNER JOIN Dept d ON e.deptno = d.deptno
    GROUP BY
      d.DNAME,
      d.DEPTNO
  ) as r ON e.sal = r.max_sal
  and e.deptno = r.deptno
ORDER BY
  r.deptno;

dname       deptno  NO_OF_EMP  ENAME  JOB        SAL
----------  ------  ---------  -----  ---------  ----
ACCOUNTING  10      3          KING   PRESIDENT  5000
RESEARCH    20      5          SCOTT  ANALYST    3000
RESEARCH    20      5          FORD   ANALYST    3000
SALES       30      6          BLAKE  MANAGER    2850
sqlite>

--------------------------------------------------------------------
--NOTE : If no join, then CrossProduct will happen.

sqlite> SELECT  COUNT(*) FROM Employee;
COUNT(*)
--------
14
sqlite> SELECT  COUNT(*) FROM Dept;
COUNT(*)
--------
4
sqlite> SELECT COUNT(*) FROM Employee, Dept;
COUNT(*)
--------
56
sqlite>

--------------------------------------------------------------------
sqlite> .show
        echo: off
         eqp: off
     explain: auto
     headers: on
        mode: column --wrap 60 --wordwrap off --noquote
   nullvalue: ""
      output: stdout
colseparator: "|"
rowseparator: "\n"
       stats: off
       width: 0 0 0 0 0 0 0 0 0 0 0
    filename: mydb


-----------------------------------------------
sqlite3 mydb --header --column "SELECT * FROM Employee, Dept" > Dept.txt

ratan@ratan-VirtualBox:~$ sed -n "40,45 p" Dept.txt | grep -i "CLERK"
7876   ADAMS   CLERK      7788  12-MAR-1983  1100        20      10      ACCOUNTING  NEW YORK
7876   ADAMS   CLERK      7788  12-MAR-1983  1100        20      20      RESEARCH    DALLAS
7876   ADAMS   CLERK      7788  12-MAR-1983  1100        20      30      SALES       CHICAGO

----------
ratan@ratan-VirtualBox:~/Desktop$ cat SomeCmds.txt
cal 12
date
whoami
pwd
ls -ltr
env

ratan@ratan-VirtualBox:~/Desktop$ cat SomeCmdToExec.sh
#! /bin/bash

while read cmd
do
	echo "Cmd : " "$cmd"
	$cmd > /dev/null
	if [ $? -eq 0 ]
	then
		echo "$cmd is Excuted Successfully."
	else
		echo "command Exceution Failed !!!"
	fi
done < ./SomeCmds.txt

---------------------------------------------------
