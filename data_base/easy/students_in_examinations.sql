SELECT
    Students.student_id,
    Students.student_name,
    Subjects.subject_name,
    COUNT(Examinations.subject_name) AS attended_exams
FROM
    Examinations
    CROSS JOIN
    Subjects
    LEFT OUTER JOIN
    Students
    ON (
        Subjects.subject_name = Examinations.subject_name
        AND Examinations.student_id = Students.student_id
    )
GROUP BY
    Students.student_id,
    Students.student_name,
    Subjects.subject_name
ORDER BY 
    Students.student_id,
    Subjects.subject_name
;