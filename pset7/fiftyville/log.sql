-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description FROM crime_scene_reports WHERE day = 28 AND year = 2020 AND month = 7 AND street = "Chamberlin Street";

SELECT transcript FROM interviews WHERE day = 28 AND year = 2020 AND month = 7 AND transcript LIKE  "%courthouse%";


--Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away. If you have security footage from the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame.
--I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at the courthouse, I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.
--As the thief was leaving the courthouse, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.


SELECT name, phone_number FROM courthouse_security_logs JOIN people ON courthouse_security_logs.license_plate = people.license_plate WHERE day = 28 AND year = 2020 AND month = 7 AND hour = 10 AND activity = "exit" AND minute > 15 AND minute < 25;


/*name | phone_number
Patrick | (725) 555-4692
Ernest | (367) 555-5533
Amber | (301) 555-4174
Danielle | (389) 555-5198
Roger | (130) 555-0289
Elizabeth | (829) 555-5269
Russell | (770) 555-1861
Evelyn | (499) 555-9472
*/

SELECT name FROM atm_transactions JOIN bank_accounts ON bank_accounts.account_number = atm_transactions.account_number JOIN people ON bank_accounts.person_id = people.id WHERE day = 28 AND year = 2020 AND month = 7 AND atm_location = "Fifer Street" AND transaction_type = "withdraw";

/*
Ernest
Robert
Russell
Roy
Bobby
Elizabeth
Danielle
Madison
Victoria
*/

--Hence we narrow it down to Ernest, Russell, Elizabeth, Danielle

SELECT name FROM people WHERE people.passport_number IN (SELECT passport_number FROM passengers WHERE flight_id IN (SELECT id FROM flights WHERE year = 2020 AND month = 7 AND day = 29 ORDER BY hour ASC LIMIT 1));

/*
Bobby
Roger
Madison
Danielle
Evelyn
Edward
Ernest
Doris
*/

--We narrow it further to, Ernest, Danielle


SELECT name FROM people WHERE people.phone_number IN (SELECT caller FROM phone_calls WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60);

/*
Bobby
Roger
Victoria
Madison
Russell
Evelyn
Ernest
Kimberly
*/
--Hence it is Ernest.

SELECT city FROM airports WHERE id IN (SELECT destination_airport_id FROM flights WHERE year = 2020 AND month = 7 AND day = 29 ORDER BY hour, minute ASC LIMIT 1);

--City is London.

SELECT name FROM phone_calls JOIN people ON phone_calls.receiver = people.phone_number WHERE caller = "(367) 555-5533" AND day = 28 AND duration < 60;

--Accomplice is Berthold.