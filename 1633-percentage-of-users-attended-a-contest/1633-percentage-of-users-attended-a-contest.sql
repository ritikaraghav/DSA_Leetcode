# Write your MySQL query statement below
Select
    contest_id , 
    Round(count(distinct user_id)*100/(select Count(user_id) from users),2) as percentage 
    from Register 
        group by contest_id
        order by percentage DESC, contest_id;
