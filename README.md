# 74HC595 (16 LEDS)

Este projeto foi desenvolvido por volta de 2020 durante o Ensino Técnico (integrado ao Ensino Médio) como parte de uma avaliação. Ele utiliza o CI 74HC595 para controlar 16 LEDs através de um registro de deslocamento serial para paralelo. O projeto implementa diversos efeitos de iluminação nos LEDs, com base em uma sequência de controle enviada ao CI.

## Componentes Utilizados

- Arduino (ou microcontrolador compatível)
- CI 74HC595 (registro de deslocamento)
- 16 LEDs
- Resistores para limitar a corrente dos LEDs
- Protoboard e jumpers para conexões

## Conexões

Os pinos do Arduino são conectados ao 74HC595 da seguinte forma:

- `clockPin` (pino 5): Controla o sinal de clock.
- `latchPin` (pino 6): Controla o latch (trava de dados) do 74HC595.
- `dataPin` (pino 7): Envia os dados de saída para os LEDs.

Os LEDs são conectados às saídas do 74HC595.

![Captura de tela 2024-09-30 145947](https://github.com/user-attachments/assets/4347fdf8-e211-4823-9fbf-caf1e378fd23)

![Captura de tela 2024-09-30 150016](https://github.com/user-attachments/assets/244ea067-8921-4eb7-90d8-a0d333698dba)

![Captura de tela 2024-09-30 150043](https://github.com/user-attachments/assets/7707c1dc-f163-435f-8671-49e4f35cdb05)


## Código

O código Arduino é responsável por controlar a sequência de iluminação dos LEDs. Ele utiliza um array booleano para representar o estado de cada LED (ligado ou desligado) e implementa 16 diferentes efeitos de iluminação, descritos abaixo:

### Efeitos Implementados

1. **Efeito 1**: Acende um LED por vez da esquerda para a direita.
2. **Efeito 2**: Acende um LED por vez da direita para a esquerda.
3. **Efeito 3**: Acende todos os LEDs de forma sequencial da esquerda para a direita.
4. **Efeito 4**: Acende todos os LEDs de forma sequencial da direita para a esquerda.
5. **Efeito 5**: Combinação dos efeitos 1 e 4.
6. **Efeito 6**: Combinação dos efeitos 2 e 3.
7. **Efeito 7**: Acende os LEDs de fora para dentro.
8. **Efeito 8**: Acende os LEDs de dentro para fora.
9. **Efeito 9**: Versão inversa do efeito 5.
10. **Efeito 10**: Versão inversa do efeito 6.
11. **Efeito 11**: Acende um LED aleatório.
12. **Efeito 12**: Acende dois LEDs aleatórios.
13. **Efeito 13**: Acende LEDs pares e ímpares alternadamente.
14. **Efeito 14**: Acende LEDs em grupos de 4.
15. **Efeito 15**: LEDs vão e voltam até completar a sequência.
16. **Efeito 16**: Sequência em pares alternados.

## Funções

- `setup()`: Configura os pinos do Arduino como saída e inicializa o sistema.
- `atualizar()`: Envia o estado atual dos LEDs para o CI 74HC595.
- `limpar()`: Desliga todos os LEDs.
- `loop()`: Executa continuamente todos os efeitos em sequência.

## Como Usar

1. Conecte os componentes de acordo com o diagrama de conexão.
2. Carregue o código no Arduino.
3. Os LEDs começarão a executar os efeitos de forma sequencial.

## Melhorias Futuras

- Adicionar mais efeitos de iluminação.
- Implementar controle via botões para selecionar diferentes efeitos.

## Licença

Este projeto foi desenvolvido para fins educacionais e pode ser modificado e distribuído livremente.
