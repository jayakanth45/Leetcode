# Write your MySQL query statement below
SELECT 
    s.student_id, 
    s.student_name,
    sj.subject_name,
    COUNT(e.student_id) AS attended_exams
FROM Students s
CROSS JOIN Subjects sj 
LEFT JOIN Examinations e
    ON s.student_id = e.student_id AND sj.subject_name = e.subject_name
GROUP BY s.student_id, sj.subject_name
ORDER BY s.student_id ASC, sj.subject_name ASC;
