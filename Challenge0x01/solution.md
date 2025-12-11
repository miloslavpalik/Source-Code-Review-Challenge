# Overview
This program simulates a tiny service that serves documents. It trusts a client-supplied `role` field (as if it came from a header) and uses that to permit access to any user's private document. That is the classic Broken Access Control.
## Vulnerability explanation
The program uses `req.role` which is provided by the client to decide whether to allow access. An attacker can simply claim `role=admin` and bypass ownership checks. Authorization decisions must be made using trusted server-side data (session store, validated token, database). Relying on client-supplied claims allows trivial privilege escalation. `TrundleTheHacker` (an attacker) was not the document owner, yet by claiming `admin` the program granted access. In a real server this would be an attacker tampering with headers or parameters.
```
./challenge1 
Simple Document Service
Enter claimed user (Trundle/John Doe): TrundleTheHacker
Enter claimed role (user/admin): admin
Which user's document to access (Trundle/John Doe): John Doe

[OK] Access granted. Document contents:
John's secret: ssn=001-2054-751
```