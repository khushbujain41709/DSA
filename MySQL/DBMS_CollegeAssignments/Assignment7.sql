DELIMITER $$
CREATE FUNCTION add_numbers(a INT, b INT)
RETURNS INT
DETERMINISTIC
BEGIN
    RETURN a + b;
END $$
DELIMITER ;

CREATE FUNCTION subtract_numbers(a INT, b INT)
RETURNS INT
DETERMINISTIC
RETURN a - b;

CREATE FUNCTION multiply_numbers(a INT, b INT)
RETURNS INT
DETERMINISTIC
RETURN a * b;

CREATE FUNCTION divide_numbers(a INT, b INT)
RETURNS DECIMAL(10,2)
DETERMINISTIC
RETURN IF(b = 0, NULL, a / b);

DELIMITER $$
CREATE FUNCTION to_upper(str VARCHAR(255))
RETURNS VARCHAR(255)
DETERMINISTIC
BEGIN
    RETURN UPPER(str);
END $$
DELIMITER ;

DELIMITER $$
CREATE FUNCTION days_between(date1 DATE, date2 DATE)
RETURNS INT
DETERMINISTIC
BEGIN
    RETURN DATEDIFF(date2, date1);
END $$
DELIMITER ;

DELIMITER $$

CREATE FUNCTION calculate_bonus(salary DECIMAL(10,2), rating INT)
RETURNS DECIMAL(10,2)
DETERMINISTIC
BEGIN
    DECLARE bonus_rate DECIMAL(5,2);
    IF rating = 5 THEN
        SET bonus_rate = 0.20;
    ELSEIF rating = 4 THEN
        SET bonus_rate = 0.15;
    ELSEIF rating = 3 THEN
        SET bonus_rate = 0.10;
    ELSEIF rating = 2 THEN
        SET bonus_rate = 0.05;
    ELSE
        SET bonus_rate = 0.00;
    END IF;
    RETURN salary * bonus_rate;
END $$
DELIMITER ;

DELIMITER $$
CREATE FUNCTION is_valid_email(email VARCHAR(255))
RETURNS BOOLEAN
DETERMINISTIC
BEGIN
    RETURN email REGEXP '^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$';
END $$
DELIMITER ;

SELECT add_numbers(10, 5);                 -- 15
SELECT to_upper('khushbu jain');           -- KHUSHBU JAIN
SELECT days_between('2024-01-01','2024-02-01'); -- 31
SELECT calculate_bonus(50000, 4);          -- 7500
SELECT is_valid_email('test@gmail.com');   -- 1
