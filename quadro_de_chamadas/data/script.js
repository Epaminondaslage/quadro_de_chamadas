
function atualizarStatus() {
  fetch('/status.json')
    .then(res => res.json())
    .then(data => {
      document.getElementById('temp').textContent = data.temperatura;
      document.getElementById('umid').textContent = data.umidade;
      document.getElementById('buzzer').textContent = data.buzzer ? "Ligado" : "Desligado";
      for (let i = 1; i <= 4; i++) {
        let el = document.getElementById("e" + i);
        el.className = "bolinha " + (data["entrada" + i] ? "green" : "red");
      }
    });
}

function desativarBuzzer() {
  fetch('/mute');
}

setInterval(atualizarStatus, 1000);
