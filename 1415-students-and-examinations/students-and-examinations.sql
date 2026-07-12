# Write your MySQL query statement below
select T.student_id,T.student_name,T.subject_name,count(E.student_id) as attended_exams
from ( SELECT s.student_id,
       s.student_name,
       sub.subject_name
FROM Students s
CROSS JOIN Subjects sub)T
LEFT JOIN Examinations AS E
ON T.student_id = E.student_id
AND T.subject_name = E.subject_name
group by student_id,student_name,subject_name
order by student_id,subject_name;