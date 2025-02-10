# Embarca Tech Servomotor

# EmbarcaTechContadorMatrizDeLed

**Video do funcionamento:** 

Projeto desenvolvido durante a primeira fase da residência Embarcatech.

Este projeto utiliza um Raspberry Pi Pico para controlar um servomotor via simulação wokwi.

## Recursos e Funcionalidades

- Controle de servomotor via pwm
- Ocilação entre diferentes graus do servomotor

## Componentes Utilizados
- Microcontrolador Raspberry Pi Pico.
- Servomotor

## Dependências
- Biblioteca pico-sdk para programação do Raspberry Pi Pico.
- Uso de hardware/pwm para manipulação dos periféricos do Raspberry Pi Pico.

## Estrutura do Código
- main.c: Contém a lógica principal do programa, incluindo inicialização de hardware e controle do servomotor

## Instalação

Clone este repositório e configure o ambiente de desenvolvimento do Raspberry Pi Pico utilizando o pico-sdk.

```bash
git clone https://github.com/MariaP-Ramalho/EmbarcaTechServomotor.git
cd EmbarcaTechServomotor
mkdir build
cd build
cmake ..
make
```

## Como Executar

- Compile o código
- Inicie a simulação wokwi através do arquivo diagram.json
