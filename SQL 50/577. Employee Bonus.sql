// In the loving memory of Popu💖
# Write your MySQL query statement below

SELECT e.name, b.bonus
FROM Employee as e LEFT JOIN Bonus as b
on e.empId = b.empId
WHERE b.bonus<1000 or b.bonus is null
