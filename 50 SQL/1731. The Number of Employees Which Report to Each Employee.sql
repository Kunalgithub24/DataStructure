# Write your MySQL query statement below

select e1.employee_id, e1.name , count(e1.employee_id) as reports_count , round(avg(e2.age)) as average_age 
from employees as e1 inner join employees as e2
on e1.employee_id = e2.reports_to 
group by e1.employee_id
order by employee_id 







-- select * 
-- from employees as e1 inner join employees as e2
-- on e1.employee_id = e2.reports_to 

-- The abouve gives this : thus easier to understand \U0001f44d\U0001f3fb
-- | employee_id | name  | reports_to | age | employee_id | name  | reports_to | age |
-- | ----------- | ----- | ---------- | --- | ----------- | ----- | ---------- | --- |
-- | 9           | Hercy | null       | 43  | 6           | Alice | 9          | 41  |
-- | 9           | Hercy | null       | 43  | 4           | Bob   | 9          | 36  |
