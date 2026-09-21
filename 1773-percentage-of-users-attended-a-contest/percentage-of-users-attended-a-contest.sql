# Write your MySQL query statement below
SELECT r.contest_id,
   ROUND (count(r.user_id) * 100.0 /(SELECT cOUNT(*) FROM users) , 2)
    AS percentage 
    FROM Register As r
    GROUP BY r.contest_id
    ORDER BY percentage DESC , contest_id ASC;