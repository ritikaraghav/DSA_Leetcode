# Write your MySQL query statement below
Select customer_id , count(customer_id) as count_no_trans from visits v left JOIN Transactions t on v.visit_id = t.visit_id  where transaction_id is null 
group by customer_id order by count_no_trans;