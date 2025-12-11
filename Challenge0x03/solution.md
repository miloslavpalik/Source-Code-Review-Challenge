# Overview
This challenge demonstrates a simple Cryptographic Failure, where the application stores passwords using a custom, reversible, non-cryptographic hash, generates session tokens using predictable time-seeded pseudo-random values, and relies on insecure and outdated practices for credential and token protection.
## Vulnerability explanation
However, we can see that `hash = (hash * 131) + c;` is a weak hash function because it uses no salt, is deterministic meaning identical passwords produce identical hashes and can be brute-forced very quickly on a GPU.
```
./challenge3
Enter username: TrundleFeelsSafeNow
Enter password: 2-0u!6-49fj2@9mc-23mdc
Registration complete.
Your session token is: 709972175
```