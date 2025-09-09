# Write your MySQL query statement below
  
select max(num) as num
from mynumbers
where num in (
    select num
    from mynumbers
    group by num
    having count(*) = 1
)

-- having count(*) = 1 means it'll only return that one or single or distinct 
-- max(num)  this means max out of all the single numbers
