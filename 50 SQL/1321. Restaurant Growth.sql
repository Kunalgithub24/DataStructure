# Write your MySQL query statement below

select visited_on,
(   #this calculate the total amount between:   date_sub( "(7-6)=1" ) and c.visited_on ( "7" )
    select sum(amount)
    from customer
    where visited_on between date_sub(c.visited_on , interval 6 day) and c.visited_on # here c.visited on means "7"
) amount,round((
    #this calculates the average sum 
    select sum(amount)/7
    from customer
    where visited_on between date_sub(c.visited_on , interval 6 day) and c.visited_on #
),2) average_amount

from customer c
where visited_on >= (
    select date_add(min(visited_on) , interval 6 day)
    from customer
)
group by visited_on
order by visited_on
