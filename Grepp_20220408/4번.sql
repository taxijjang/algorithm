SELECT BRANCH_ID, count(e.BRANCH_ID) as "계약 건수" from EMPLOYEES as e
join SELLINGS as s
on e.ID = s.EMPLOYEE_ID
group by (e.BRANCH_ID)
order by e.BRANCH_ID
