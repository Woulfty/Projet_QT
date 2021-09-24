//VM
var socket = new WebSocket("ws://192.168.64.183:1234");
//local
//var socket = new WebSocket("ws://192.168.65.62:1234");
socket.onopen = function(event) { onOpen(event); };
socket.onmessage = function(event) { onMessage(event); };
        
// Lorsque le serveur envoi un message.
this.onmessage = function(event) {
    console.log("message:", event.data);
    return evt.data;
};

// Récupération des erreurs.
// Si la connexion ne s'établie pas,
socket.onerror = function(error) {
    console.error(error);
};

// Lorsque la connexion est établie.
socket.onopen = function(event) {
    console.log("Connexion établie.");

    // Lorsque la connexion se termine.
    this.onclose = function(event) {
        console.log("Connexion terminé.");
    };
            
};

function envoie(){
    var message =document.getElementById("message").value;
        data ="Bdd"+message;
    socket.send(data);
}    

function onMessage (evt){
    alert (evt.data);
    this.dataInput = evt.data;
}