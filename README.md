# GCC-2425-student
Dépôt des solutions donnés en exercice aux 2ème et 3ème année de GCC à e-artsup Montpellier pour l'année scolaire 2024-2025

## Configuration

* Assurez-vous d'avoir les outils suivant correctement installés :
    * WSL : [Windows Subsystem Linux](https://learn.microsoft.com/en-us/windows/wsl/install) et si nécessaire le [package de mise à jour du noyau Linux pour WSL 2](https://learn.microsoft.com/en-us/windows/wsl/install-manual#step-4---download-the-linux-kernel-update-package)
    * Un IDE (Visual Studio, CLion, Code::Blocks) ou un éditeur de code (Visual Studio Code, VSCodium, Notepad++, Vim, ...)
    * GNU/G++ et GNU Make
    ```bash
    $ sudo apt update && sudo apt install build-essential
    $ g++ --version # vérifier que g++ est bien installé
    $ make --version # vérifier que make est bien installé
    ```
    * Cmake version 3.24.1 au minimum
    ```bash
    $ sudo apt update && sudo apt install cmake
    $ cmake --version # vérifier que cmake est bien installé
    ```

Vous trouverez dans chaque projet du dépôt un `CmakeLists.txt` le plus basique qu'il soit mais efficace ainsi qu'un script `build.sh` pour WSL ou `build.bat` pour Windows utilisables comme suit :
* `./build.sh -a` ou `.\build.bat -a` : Configurer puis construire le projet
* `./build.sh -m` ou `./build.bat -m` : Uniquement construire le projet (nécessite d'avoir été configuré avec la commande `-a` une première fois)
* `./build.sh -r` ou `./build.bat -r` : Permet d'executer le projet (nécessite d'avoir été configuré `-a` et/ou construit `-m`)

Vous avez la possibilité de passer des arguments au programme après l'option `-r`. Par exemple :
```bash
$ ./build.sh -r 2
```

Cette commande permettra d'executer le programme `tp0` et de lui envoyer l'argument `2` comme si nous avions fait `./tp 2` dans le prompt.
On pourra alors récupérer l'argument à l'aide du paramètre `char** argv` de la méthode `main` en faisant comme suit :
```cpp
int main (int argc, char** argv)
{
    int n(0);
    // On ne récupère qu'un seul argument ici
    if(argc > 1 && argc < 3)
    {
        n = std::stoi(argv[1]);
    }
}
```

> **Attention**: Assurez-vous d'avoir les droits d'exécution sur le script `build.sh` si vous l'utilisez sur un prompt bash/zsh. Pour ce faire, exécutez la commande `chmod 744 ./build.sh`.