/*
Write a Stored Procedure namely proc_Grade for the categorization of student.
If marks scored by students in examination is <=1500 and marks>=990 then student will be placed in distinction category,
if marks scored are between 989 and900 category is first class, if marks 899 and 825 category is Higher Second Class.
Write a PL/SQL block for using procedure created with above requirement. Stud_Marks(name, total_marks) Result(Roll,Name, Class)*/

use mock_test;

create table Stud_Marks(
	roll int not null auto_increment,
	student_name varchar(30),
    total_marks int default 0,
    primary key (roll)
);

create table Result(
	roll varchar(5),
    student_name varchar (30),
    class varchar (20)
);

delimiter //
create procedure proc_Grade()
begin
	declare roll_no int;
    declare stud_name varchar(30);
    declare marks int;
    
    declare finished int default 0;
    declare cycle cursor for select * from Stud_Marks;
    declare continue handler for not found set finished = 1;
    open cycle;
    
    delete from Result;
    
    loop_label: LOOP
		if finished = 1 then
			leave loop_label;
		end if;
        
        fetch cycle into roll_no, stud_name, marks;
        if marks <= 1500 and marks >=990 then
			insert into Result value (roll_no, stud_name, 'Distinction');
		elseif marks > 900 then
			insert into Result value (roll_no, stud_name, 'First Class');
		elseif marks >= 825 then
			insert into Result value (roll_no, stud_name, 'Higher Second Class');
		else
			insert into Result value (roll_no, stud_name, '------');
		end if;
    end LOOP;
    close cycle;
    select * from Result;
end//
delimiter ;

create function get_Grade(roll_no int)
returns varchar(20) deterministic
return (select class from Result where roll = roll_no);

insert into Stud_Marks value(24, 'George Washington', 842);

insert into Stud_Marks(student_name, total_marks) values
('John Adams', 1024),
('Thomas Jefferson', 1421),
('James Madison', 1124),
('James Monroe', 1400),
('John Q Adams', 950),
('Andrew Jackson', 945),
('Martin Van Buren', 790),
('John Tyler', 1340),
('Zachary Taylor', 754),
('Millard Fillmore', 1450),
('Franklin Pierce', 1260),
('James Buchanan', 899);

select * from Stud_Marks;
select * from Result;

call proc_Grade();
select get_Grade(30);

delete from Stud_Marks;
delete from Result;

drop procedure proc_Grade;
drop table Stud_Marks;
drop table Result;