/* Write your T-SQL query statement below */
/* Write your T-SQL query statement below */


select 
contest_id, 
round(count(distinct user_id) * 100 /(select count(user_id) from Users) ,2) as percentage
from  Register
group by contest_id
order by percentage desc,contest_id


# Got it 👍 Let’s break this down step by step:

-- ```sql
-- ROUND(
--     COUNT(r.user_id) * 100.0 / (SELECT COUNT(u.user_id) FROM Users u), 
--     2
-- ) AS percentage
-- ```

-- This expression is calculating the **percentage of users who registered for each contest**, and then rounding the result to **2 decimal places**.

-- ---

-- ### 1. `COUNT(r.user_id)`

-- This counts how many users registered for a particular contest (because we’re grouping by `contest_id`).

-- Example: If 25 users registered for contest `101`, then `COUNT(r.user_id)` = 25 for that group.

-- ---

-- ### 2. `(SELECT COUNT(u.user_id) FROM Users u)`

-- This subquery counts the **total number of users in the system**.

-- Example: If the `Users` table has 200 total users, this will return `200`.

-- ---

-- ### 3. `COUNT(r.user_id) * 100.0 / (SELECT COUNT(u.user_id) ...)`

-- This calculates the **percentage of users** that registered for the contest.

-- * Multiplying by `100.0` ensures we get a **decimal percentage** (not integer division).
-- * Example:

--   * 25 registered users
--   * 200 total users
--   * `(25 * 100.0 / 200)` = `12.5`

-- ---

-- ### 4. `ROUND(..., 2)`

-- This rounds the result to **2 decimal places**.

-- * Without rounding, you might get: `12.500000000000001`
-- * With rounding: `12.50`

-- ---

-- ### 5. `AS percentage`

-- This just gives the calculated column a name (`percentage`) in the result set.

-- ---

-- ✅ **Final Example Output**
-- If there are 200 total users:

-- | contest\_id | percentage |
-- | ----------- | ---------- |
-- | 101         | 12.50      |
-- | 102         | 37.00      |
-- | 103         | 45.50      |

-- ---

-- Do you want me to also explain **why we used `100.0` instead of just `100`**?
