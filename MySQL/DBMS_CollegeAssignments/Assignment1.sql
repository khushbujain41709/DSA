CREATE DATABASE Assignment1;

USE Assignment1;

CREATE TABLE films(film_id INT AUTO_INCREMENT PRIMARY KEY, title VARCHAR(50) NOT NULL, genre VARCHAR(50), release_year INT, ratings FLOAT, duration_minutes FLOAT);

CREATE TABLE directors(director_id INT AUTO_INCREMENT PRIMARY KEY, fname VARCHAR(50), lname VARCHAR(50), birth_year INT, nationality VARCHAR(50));

INSERT INTO films(title, genre, release_year, ratings, duration_minutes) VALUES ("3 Idiots", "Comedy", 2009, 8.4, 170), ("Seven", "Crime", 1995, 8.6, 127), ("Inception", "Sci-Fi", 2010, 8.8, 148), ("Titanic", "Romance", 1997, 7.9, 194);

INSERT INTO films(title, genre, release_year, ratings, duration_minutes) VALUES ("3 Idiots", "Comedy", 2009, 9.4, 150);

INSERT INTO directors(fname, lname, birth_year, nationality) VALUES ("Christopher", "Nolan", 1970, "London"),("David", "Fincher", 1962, "Denver"), ("Rajkumar", "Hirani", 1962, "Nagpur"), ("Peter", "Jackson", 1961, "New Zealand");

ALTER TABLE films RENAME COLUMN ratings TO IMDB_ratings;

SELECT * FROM films;

SELECT * FROM directors;