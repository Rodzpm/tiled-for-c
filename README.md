# tiled-for-c

## How to use it

- créer une map avec Tiled et l'exporter en json
- déplacer la map dans le dossier assets ainsi que tous les tilesets utilisés
- activer l'environnement virtuel
```bash
source env/bin/activate
```
- aller dans le dossier assets
- lancer le programme tiled_for_c.py
```bash
python tiled_for_c.py name_of_your_map.json
```
- sortir du dossier assets puis compiler
```bash
cd ..
make
./my_rpg
```
