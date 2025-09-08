# Write your MySQL query statement below

SELECT s.user_id,

    ROUND(SUM(CASE WHEN c.action = "confirmed" THEN 1 ELSE 0 END)/COUNT(*),2) As confirmation_rate


FROM 
Signups as s LEFT JOIN 
Confirmations as c
on c.user_id = s.user_id

Group by s.user_id
ORDER BY confirmation_rate 

# Popu 💖
