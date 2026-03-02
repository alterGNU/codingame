# My Codingame Puzzle Solutions

## Solo: Easy
| Title                                                                                        | Python | C   | C++ | Golf   |
|----------------------------------------------------------------------------------------------|--------|-----|-----|--------|
| [Power Of Thor - Episode 1](https://www.codingame.com/training/easy/power-of-thor-episode-1) | ✅     | ✅  | ✅  | ❌     |
| [Temperatures](https://www.codingame.com/training/easy/temperatures)                         | ✅     | ✅  | ✅  | py:117 |
| [ASCII Art](https://www.codingame.com/training/easy/ascii-art)                               | ✅     | ✅  | ✅  | py:206 |
| [Ghost Legs](https://www.codingame.com/training/easy/ghost-legs)                             | ✅     | ✅  | ✅  | py:272 |
| [The Descent](https://www.codingame.com/training/easy/the-descent)                           | ✅     | ✅  | ✅  | py:61  |
| [Onboarding](https://www.codingame.com/training/easy/onboarding)                             | ✅     | ✅  | ✅  | py:66  |
| [Defibrillators](https://www.codingame.com/training/easy/defibrillators)                     | ✅     | ✅  | ❌  | py:342 |

## Solo: Medium
## Solo: Hard
## Solo: Very_Hard

## Notes:
- Count word/char/byte in selected lines (vim editor): `[g]+[Ctrl]+[g]`-->display infos in bar
### C
#### Split string by sep
- Problem with `strtok`--> treats consecutive delimiters as **one single separator**...
    ```c
    char *token = strtok(str, ";");
    while (token)
    {
        ...
        var = token;
        ...
        token = strtok(NULL, ";");
    }
    ```
    - will work if all fields not empty, but for `1;Maison;Address;;3.13;3.14` will skip missing phonenumber.
- Instead use `strsep`--> handle empty fields.
    ```c
    int loop = 1;
    char *token;
    while ((token = strsep(&str, ";")) != NULL)
    {
        printf("[%d]->'%s'\n", loop, token);
        loop++;
    }
    ```
