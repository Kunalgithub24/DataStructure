# Write your MySQL query statement below
# Love Popu 💖


SELECT e1.name

FROM Employee as e1
JOIN Employee as e2
on e1.id = e2.managerId

GROUP BY e2.managerId HAVING COUNT(*)>= 5
