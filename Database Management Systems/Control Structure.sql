/*
Write a PL/SQL block of code for the following requirements:- Schema:
1. Borrower(Rollin, Name, DateofIssue, NameofBook, Status)
2. Fine(Roll_no,Date,Amt)
	a) Accept roll_no & name of book from user.
	b) Check the number of days (from date of issue), if days are between 15 to 30 then fine amount will be Rs 5per day.
    c) If no. of days>30, per day fine will be Rs 50 per day & for days less than 30, Rs. 5 per day.
    d) After submitting the book, status will change from I to R.
    e) If condition of fine is true, then details will be stored into fine table.*/

create database mock_test;

use mock_test;

create table borrower(
	Roll_No int auto_increment,
    Student varchar(30),
    DateofIssue date,
    NameofBook varchar(30),
    Status varchar(1) default 'I',
    primary key(Roll_No)
);

create table Fine(
	Roll_No int not null,
    DateofIssue date,
    days int,
    fineAmount int
);

insert into borrower(roll_no, student, dateofissue, nameofbook) values
(21, 'Matt Carriker', '2020-11-04', 'Better than Yesterday'),
(74, 'Tom Scott', '2020-11-20', 'Amazing Places'),
(10, 'Hank Green', '2020-11-17', 'From a Certain Point of View'),
(11, 'John Green', '2020-10-31', 'Paper Towns'),
(34, 'Joe Hanson', '2020-11-10', 'DNA: The Book of You'),
(14, 'Derek Muller', '2020-09-24', 'Russia\'s Place in Europe'),
(27, 'Jack Douglass', '2020-11-15', 'YIAY: The Book'),
(31, 'Destin Sandlin', '2020-11-23', 'The Story of Innovation'),
(43, 'Steve Mould', '2020-10-30', 'Clever Creatures');

select * from borrower;

delimiter //
create procedure calFines()
begin
	declare roll int;
    declare doi date;
    declare stat varchar(1);
    declare days int;
    
    declare finished int default 0;
    declare cycle cursor for select roll_no, dateofissue, status from borrower;
    declare continue handler for not found set finished = 1;
    
    open cycle;
    
    delete from fine;
    
    loop_label: LOOP
		if finished = 1 then
			leave loop_label;
		end if;
    
		fetch cycle into roll, doi, stat;
        if stat = 'R' then
			iterate loop_label;
		end if;
        
        set days = datediff(current_date(), doi);
        if days > 15 and days <= 30 then
			insert into fine value(roll, doi, days, (5 * days));
		end if;
        
        if days > 30 then
			insert into fine value(roll, doi, days, (50 * days));
		end if;
        
	end LOOP loop_label;
    close cycle;
end//
delimiter ;

delimiter //
create procedure returnBook(IN roll int, IN bookName varchar(50))
begin
	declare finished int default 0;
    declare rollNo int;
    declare book varchar(50);
    declare fineAmt int default 0;
    declare cycle cursor for select roll_no, NameofBook from borrower; 
	declare continue handler for not found set finished = 1;
    open cycle;
    
    call calFines();
    loop_label: LOOP
		if finished = 1 then
			leave loop_label;
		end if;
        
        fetch cycle into rollNo, book;
        if roll = rollNo and bookName = book then
			update borrower set status = 'R' where roll_no = roll;
            set fineAmt = (select fineAmount from fine where Roll_No = roll);
            set finished = 1;
		end if;
    end LOOP;
    close cycle;
    select fineAmt as 'Fine to be Paid';
end//
delimiter ;

update borrower set status = 'I' where roll_no = 21 or roll_no = 27 or roll_no = 43;

call calFines();
select * from fine;

select * from borrower;

call returnBook(21, 'Better than Yesterday');
call returnBook(27, 'YIAY: The Book');
call returnBook(43, 'Clever Creatures');

drop table borrower;
drop table fine;
drop procedure calFines;
drop procedure returnBook;