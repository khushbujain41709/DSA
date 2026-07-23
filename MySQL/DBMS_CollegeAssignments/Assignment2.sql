USE Assignment1;

CREATE TABLE members(member_id INT AUTO_INCREMENT PRIMARY KEY, fname VARCHAR(50) NOT NULL, lname VARCHAR(50) NOT NULL, address VARCHAR(100), city VARCHAR(50), zip_code INT, DOB DATE, join_date DATE);

INSERT INTO members (member_id, fname, lname, address, city, zip_code, DOB, join_date) VALUES (1, 'Khushbu', 'Jain', 'Chhattisgarh', 'Durg', 491001, '2003-11-01', '2023-08-22'), (2, 'Manasvi', 'Nair', 'Chhattisgarh', 'Bhilai', 490002, '2005-02-04', '2015-01-01'), (3, 'Lakshita', 'Chandrakar', 'Chhattisgarh', 'Bhilai', 490002, '2004-05-18', '2020-11-01'), (4, 'Niti', 'Jain', 'Telangana', 'Hyderabad', 491001, '1989-09-12', '2020-12-21'),(5, 'Lisa', 'Sao', 'Thane', 'Mumbai', 490002, '2005-02-04', '2020-01-01');

SELECT fname, lname, address FROM members WHERE join_date BETWEEN '2015-01-01' AND '2015-01-31';

SELECT fname, lname FROM members WHERE city = 'Mumbai' AND TIMESTAMPDIFF(YEAR, DOB, CURDATE()) > 16;

INSERT INTO films (title, genre, release_year, ratings, duration_minutes) VALUES ('PLANET HUNT', 'Sci-Fi', 2012, 4.5, 135), ('Silent Wave', 'Drama', 2015, 3.8, 120);

SELECT title, ratings FROM films WHERE ratings BETWEEN 3 AND 5;

SELECT* FROM films WHERE title >= 'P' AND title <= 'T' AND (release_year < 1980 AND release_year >= 1990);

SELECT fname, lname, zip_code FROM members WHERE zip_code LIKE '49%';

SELECT* FROM members ORDER BY DOB DESC;

SELECT* FROM members WHERE join_date < '2020-12-31' ORDER BY lname, fname;