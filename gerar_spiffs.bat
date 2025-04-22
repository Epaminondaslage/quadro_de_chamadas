@echo off
setlocal EnableDelayedExpansion

:: Caminhos e configurações (ajuste se necessário)
set MKSPIFFS="C:\Users\epami\AppData\Local\Arduino15\packages\esp32\tools\mkspiffs\0.2.3\mkspiffs.exe"
set PORT=COM8
set SIZE=0x150000
set ADDRESS=0x290000

echo ===============================================
echo  GERANDO SPIFFS.BIN E ENVIANDO PARA O ESP32
echo ===============================================

:: Verifica se mkspiffs.exe existe
if not exist %MKSPIFFS% (
    echo [ERRO] mkspiffs.exe nao encontrado em: %MKSPIFFS%
    pause
    exit /b
)

:: Cria a imagem SPIFFS usando a pasta correta
echo [1] Gerando imagem spiffs.bin da pasta .\quadro_de_chamadas\data
%MKSPIFFS% -c .\quadro_de_chamadas\data -b 4096 -p 256 -s %SIZE% spiffs.bin

if not exist spiffs.bin (
    echo [ERRO] A imagem spiffs.bin nao foi gerada!
    pause
    exit /b
)

:: Enviando a imagem para o ESP32 com esptool
echo [2] Enviando spiffs.bin para o ESP32 via porta %PORT%
python -m esptool --chip esp32 --port %PORT% --baud 460800 write_flash %ADDRESS% spiffs.bin

echo [OK] Processo finalizado com sucesso.
pause
