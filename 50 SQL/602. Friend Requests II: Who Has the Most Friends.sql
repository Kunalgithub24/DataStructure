
# Write your MySQL query statement below

-- **intution :
--                total 
-- 1 -> 1 + 1       = 2
-- 2 -> 1 + 1       = 2
-- 3 -> 1 + 1 + 1   = 3
-- 4 -> 1           = 1

-- 3 has most friends 



-- **to under standing purpose ..
-- select requester_id  id
-- from RequestAccepted

-- union all # used this becx it gives all the duplicates also | id |
-- | id |
-- | -- |
-- | 1  |
-- | 1  |
-- | 2  |
-- | 3  |
-- | 2  |
-- | 3  |
-- | 3  |
-- | 4  |

-- select accepter_id 
-- from RequestAccepted


select id, count(id) as num
from (
select requester_id  id from RequestAccepted
union all
    select accepter_id from RequestAccepted
) as first
group by id
order by num desc
limit 1
