
## Disclaimer
**learn.cpp.fundamental** is an independent educational resource created to share knowledge and experiences related to learning C++ computer programming.

> [!IMPORTANT]
> #### Please note: The content may contain inaccuracies, as this is a learning journey.  
#
#
### BUILD
```bash
#REM: All subprojects.
gradlew build

#REM: gradlew <subproj_name>:build
#REM: e.q. log subproj.
gradlew log:build

#REM: e.q. value-semantic subproj.
gradlew value-semantic:build
```
#
### TEST
```bash
#REM: All subprojects.
gradlew test --rerun-tasks

#REM: gradlew <subproj_name>:test [--rerun-tasks]
#REM: e.q. log subproject.
gradlew log:test --rerun-tasks

#REM: e.q. value-semantic subproject.
gradlew value-semantic:test --rerun-tasks
``` 
#
### PUBLISH
```bash
#REM: e.q. log subproject.
gradlew log:publisAllPublicationsToLocalRepository

#REM: e.q. value-semantic subproject.
gradlew value-semantic:publishAllPublicationsToLocalRepository
```
> [!NOTE]: It will publish it relative to the root project dir.