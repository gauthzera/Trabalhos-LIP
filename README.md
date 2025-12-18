# Trabalhos-LIP

Repositório para a disciplina de "Laboratório de introdução à computação"
Links:

Simon Genius Game: https://www.tinkercad.com/things/jYAPT8wHKZt-projetosimonlip

Primeiro projeto - Semáforo: https://www.tinkercad.com/things/kDFEkaO5J89-semaforo-lip 

Segundo projeto - ODS: https://www.tinkercad.com/things/4TaOUXWc9tU-projeto-lip-2 

## Documentação segundo projeto
Iluminação Pública Adaptativa para Segurança e Eficiência
Integrantes: Gabriel Ulhoa, Samuel Elias e Rhayner Martins
ODS Escolhidos:
- ODS 7 – Energia Limpa e Acessível
- ODS 11 – Cidades e Comunidades Sustentáveis
Problema Real :
Em muitas cidades, a iluminação pública fica ligada em potência máxima durante toda a noite, mesmo em locais com pouco ou nenhum movimento. Isso causa um grande desperdício de energia elétrica e aumenta os custos para o poder público. Por outro lado, quando a iluminação é fraca ou mal distribuída, as pessoas sentem insegurança para circular à noite em ruas e praças. Por isso, é importante buscar uma forma inteligente de equilibrar segurança e economia de energia.
Descrição da Solução:
A ideia do projeto é criar um poste de luz inteligente que funcione em modo de economia de energia, mas que aumente automaticamente a intensidade da luz quando detectar a presença de pessoas ou veículos. Além disso, o sistema conta com um modo de emergência, que acende toda a iluminação em potência máxima quando um botão de pânico for pressionado.
Componentes Usados:
Entradas:
-Sensor de Movimento (PIR): Detecta se há pessoas ou veículos próximos.
- Sensor de Luminosidade (LDR): Mede a luz do ambiente para o sistema só funcionar à noite.
- Botão (Push Button): Ativa o modo de pânico, deixando a iluminação no máximo por alguns minutos.
Saídas:
- LED Branco: Representa o poste de luz, com intensidade controlada (luz fraca e forte).
-Buzzer: Faz barulho quando o botão for acionado.
- LED RGB: Mostra o estado do sistema:
o Azul → modo econômico
o Verde → movimento detectado
o Vermelho → modo pânico
Como o Sistema Funciona:
Durante o dia, o sistema fica desligado, pois o sensor LDR detecta que há bastante luz. Quando escurece, o LED branco acende com baixa intensidade (cerca de 30%) e o LED RGB fica azul, indicando o modo econômico. Se o sensor PIR detectar movimento, o LED branco aumenta para 100%, o LED RGB muda para verde. Depois de cerca de um minuto sem movimento, tudo volta para o modo econômico. Caso o botão seja pressionado, o sistema entra em modo pânico e o buzzer emite um barulho, acendendo o LED branco no máximo e mudando o LED RGB para vermelho por cerca de cinco minutos.
Impacto Esperado
Com esse sistema, é possível reduzir bastante o gasto de energia com iluminação pública, acendendo as luzes em potência máxima apenas quando realmente necessário. Além disso, a presença de um sistema que reage a movimentos e emite barulhos aumenta a sensação de segurança das pessoas que passam por locais públicos à noite. Assim, o projeto contribui diretamente para os ODS 7 e 11, ajudando na construção de cidades mais sustentáveis, econômicas e seguras.


## Documentação do projeto final
Iluminação Pública Adaptativa para Segurança e Eficiência
Integrantes: Gabriel Ulhoa, Samuel Elias e Rhayner Martins
ODS Escolhidos:
ODS 7 – Energia Limpa e Acessível
ODS 11 – Cidades e Comunidades Sustentáveis

Problema Real :
Em muitas cidades, a iluminação pública fica ligada em potência máxima durante toda a noite, mesmo em locais com pouco ou nenhum movimento. Isso causa um grande desperdício de energia elétrica e aumenta os custos para o poder público.
Por outro lado, quando a iluminação é fraca ou mal distribuída, as pessoas sentem insegurança para circular à noite em ruas e praças. Por isso, é importante buscar uma forma inteligente de equilibrar segurança e economia de energia.

Descrição da Solução:
A ideia do projeto é criar um poste de luz inteligente que funcione em modo de economia de energia, mas que aumente automaticamente a intensidade da luz quando detectar a presença de pessoas ou veículos.
Além disso, o sistema conta com um modo de emergência, que acende toda a iluminação em potência máxima quando um botão de pânico for pressionado.
Componentes Usados:

Entradas:
Sensor de Movimento (PIR): Detecta se há pessoas ou veículos próximos. (No vídeo não foi possível mostrar o sensor de movimento, pois tive gravar o sistema perto do shield)
Sensor de Luminosidade (LDR): Mede a luz do ambiente para o sistema só funcionar à noite.
Botão (Push Button): Ativa o modo de pânico, deixando a iluminação no máximo por alguns minutos. (não conseguimos implementar no shield)
Saídas:
LED Branco: Representa o poste de luz, com intensidade controlada (luz fraca e forte).
Buzzer: Faz barulho quando o botão for acionado. (não conseguimos implementar no shield)
LED_1 shield: O led 1 foi utilizado para simular a iluminação total do poste quando o sensor do movimento detectar uma pessoa
LED_2 shield: o led 2 foi utilizado para simular a luz fraca do poste de luz quando sensor de movimento não detectar presença (não foi possível exibir essa funcionalidade, pois o sensor de movimento sempre estava detectando a gente. Verifique o código e veja que realmente utilizamos esse led)
LED RGB: Mostra o estado do sistema:
vermelho→ modo econômico
Verde → movimento detectado
DISCLAIMER: Não encontramos sentido em implementar leitura através do monitor serial, pois nosso projeto é de uso contínuo e depende apenas de iluminação para funcionar.

Como o Sistema Funciona:

Durante o dia, o sistema fica desligado, pois o sensor LDR detecta que há bastante luz. Quando escurece, o LED branco acende com baixa intensidade (cerca de 30%) e o LED RGB fica azul, indicando o modo econômico.
Se o sensor PIR detectar movimento, o LED branco aumenta para 100%, o LED RGB muda para verde.
Depois de cerca de um minuto sem movimento, tudo volta para o modo econômico. Caso o botão seja pressionado, o sistema entra em modo pânico e o buzzer emite um barulho, acendendo o LED branco no máximo e mudando o LED RGB para vermelho por cerca de cinco minutos.
Impacto Esperado
Com esse sistema, é possível reduzir bastante o gasto de energia com iluminação pública, acendendo as luzes em potência máxima apenas quando realmente necessário.
Além disso, a presença de um sistema que reage a movimentos e emite barulhos aumenta a sensação de segurança das pessoas que passam por locais públicos à noite. Assim, o projeto contribui diretamente para os ODS 7 e 11, ajudando na construção de cidades mais sustentáveis, econômicas e seguras.

