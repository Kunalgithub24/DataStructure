
select round(count(distinct player_id) / (select count(distinct player_id) from activity),2) as fraction
from activity
where ( player_id, date_sub(event_date, interval 1 day)) in 
    (
        select player_id, min(event_date) as first_order
        from activity 
        group by player_id
    )


-- round(count(distinct player_id) give the number of player from down where claus : that is 1
-- (select count(distinct player_id) from activity) gives all the player in the table : that is  3

-- select player_id, min(event_date) as first_order
-- from activity 
-- group by player_id
-- : only gives the date thats first 

-- date_sub(event_date, interval 1 day) : thats an inbuilt finction to calculate the date and + 1 date for comparison 
