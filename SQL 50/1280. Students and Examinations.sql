# Write your MySQL query statement below
# In loving memory of POPU 💖
# I love you and you are here with me 👦🏻🐶

SELECT s.student_id, s.student_name ,su.subject_name, COUNT(e.student_id) as attended_exams

FROM Students as s
CROSS join Subjects as su
LEFT JOIN Examinations as e
on 
s.Student_id = e.Student_id and
su.subject_name = e.subject_name

group by s.student_id, s.student_name ,su.subject_name
order by s.student_id, su.subject_name
