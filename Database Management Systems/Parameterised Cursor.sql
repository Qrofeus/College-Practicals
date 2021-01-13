use college;

create table O_Roll(
	roll_no int
);

create table N_Roll(
	roll_no int
);

create table merged_roll(
	roll_no int
);

delimiter //
create procedure merge_rollNos(IN count_from_old int)
begin
	declare roll int;
    declare finished int default 0;
    
    declare cycle cursor for select * from O_Roll;
    declare continue handler for not found set finished = 1;
    
    delete from merged_roll;
    
    insert into merged_roll select * from N_Roll;
    
    open cycle;
    merger:while finished = 0 do
		fetch cycle into roll;
		if not exists(select 1 from merged_roll where roll_no = roll) then
			insert into merged_roll value(roll);
		end if;
    end while merger;
    
    close cycle;
    select * from merged_roll;
end//
delimiter ;

insert into O_Roll values(21),(54),(95),(62),(84),(63),(74),(85),(61),(2),(7),(9),(4),(42);

insert into N_Roll values(5),(35),(54),(98),(65),(84),(32),(74);

select * from O_Roll;
select * from N_Roll;
select * from merged_Roll;

call merge_rollNos();

drop table O_Roll;
drop table N_Roll;
drop table Merged_Roll;

drop procedure merge_rollNos;