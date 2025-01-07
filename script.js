document.getElementById('toggleButton').addEventListener('click', function() {
    var modules = document.getElementById('modules');
    modules.classList.toggle('show');
});

//view pdf
var buttons = document.querySelectorAll('.viewButton');
buttons.forEach(function(button) {
    button.addEventListener('click', function() {
        var url = this.getAttribute('data-url');
        openPDF(url);
    });
});

function openPDF(url) {
    window.open(url, '_blank');
}
