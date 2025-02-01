# Tarefa 2 - Simulação de semaforo utilizando temporização

## 🛠️ Componentes Utilizados

- 03 LEDs (Vermelho, amarelo e Azul)
- 01 Raspberry Pi Pico W
- Protoboard e jumpers

## 💻 Firmware

Desenvolvido em C utilizando:

- IDE: Visual Studio Code
- SDK: Raspberry Pi Pico SDK
- Simulador: Wokwi (para testes virtuais)
- LED Vermelho: GP13
- LED amarelo: GP11
- LED Azul: GP12

## 🎯 Funcionamento

### Estado Inicial

- O LED vermelho inicia ligado e o restante inicia desligado

### Fluxo de Operação:

1. Após 3 segundos:
    - LED Vermelho se apaga e o amarelo acende
    - O temporizador de 3 segundos é reativado

2. Após 6 segundos totais:
    - LED amarelo se apaga e o azul acende
    - Última temporização de 3 segundos inicia

3. Após 9 segundos totais:
    - LED azul se apaga e o amarelo acende
    - O sistema retoma o ciclo

### Explicação

Os intervalos são gerenciados pelo hardware do Pico através da função add_repeating_timer_ms, deixando-o livre para realizar outras operações.

## 👥 Autoria
**Guilherme Emetério Santos Lima**  
[![GitHub](https://img.shields.io/badge/GitHub-Profile-blue?style=flat&logo=github)](https://github.com/DankAlighieri)