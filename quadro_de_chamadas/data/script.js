function atualizarStatus() {
  fetch('/status.json')
    .then(res => res.json())
    .then(data => {
      // Atualizar temperatura
      if (typeof data.temperatura === "number") {
        document.getElementById('temp').textContent = data.temperatura.toFixed(1);
      } else {
        document.getElementById('temp').textContent = "--";
      }

      // Atualizar umidade
      if (typeof data.umidade === "number") {
        document.getElementById('umid').textContent = data.umidade.toFixed(1);
      } else {
        document.getElementById('umid').textContent = "--";
      }

      // Atualizar buzzer e botão
      const buzzerStatus = document.getElementById('buzzer');
      const buzzerButton = document.getElementById('buzzerButton');

      if (data.buzzer) {
        buzzerStatus.textContent = "Acionada";
        buzzerButton.textContent = "Desativar Som";
        buzzerButton.style.backgroundColor = "#007BFF";
      } else {
        buzzerStatus.textContent = "Desligada";
        buzzerButton.textContent = "Desativar Som";
        buzzerButton.style.backgroundColor = "#6c757d";
      }

      // Atualizar bolinhas de entradas
      for (let i = 1; i <= 4; i++) {
        const bolinha = document.getElementById('e' + i);
        if (data['entrada' + i]) {
          bolinha.classList.remove('gray');
          bolinha.classList.add('green');
        } else {
          bolinha.classList.remove('green');
          bolinha.classList.add('gray');
        }
      }
    })
    .catch(error => {
      console.error("Erro ao buscar status:", error);
    });
}

function desativarBuzzer() {
  fetch('/mute')
    .then(res => res.text())
    .then(msg => {
      alert(msg);
      atualizarStatus();
    })
    .catch(error => {
      console.error("Erro ao desativar buzzer:", error);
    });
}

setInterval(atualizarStatus, 1000);
window.onload = atualizarStatus;
