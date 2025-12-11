# Overview
This challenge is designed for individuals who already have a solid understanding of authentication concepts and want to practice applied code review. If an attacker identifies an authentication weakness, they may take over accounts, escalate privileges, hijack sessions, steal or reuse credentials, or cause significant reputation damage by compromising user trust.
## Vulnerability explanation
Plaintext password storage `users.txt` allows immediate credential theft and offline cracking without salt or hashing. We can notice also `MASTER_PASSWORD`. It's a universal credential that grants access to any account. No rate limiting, account lockout or MFA implemented. Also here is a `rand()` with current time and reseeding each call makes tokens guessable by attackers who know approximate time allows session hijacking. You can also exploit this script with non-existend user with empty password. 
```
./challenge5
Enter username: Trundle
Enter password: Trundle$Master^Password%
[OK] Authenticated as: Trundle
[INFO] Session token: 1610057288
Welcome to the secure console.
```