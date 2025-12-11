# Overview
This example mimics a scenario where a production application is accidentally shipped with debug mode enabled, verbose error logging, exposure of internal file paths, environment variables, and stack traces. This is one of the most common failures and often leads to information disclosure & further exploitation.
## Vulnerability explanation
All these details are gold for attackers performing reconnaissance, LFI/RFI exploitation, privilege escalation, or targeting internal file structures. The secure approach requires disabling debug mode in production `DEBUG_MODE = false`. Debug information often acts as a force multiplier for other vulnerabilities. Never exposing file paths, stack traces, or environment variables to users. Using centralized error handling that returns generic messages. Logging sensitive details only to secure server logs with restricted permissions.
```
Secure Data Service (debug mode enabled)
Attempting to read protected server data...

ERROR: Failed to open server_config/api_keys.txt
Current working directory: /home/user/Desktop
StackTrace: [readRestrictedSecret() -> main()]
```









