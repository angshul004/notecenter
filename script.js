document.getElementById('toggleButton').addEventListener('click', function() {
    var modules = document.getElementById('modules');
    modules.classList.toggle('show');
});

function openPDF() {
    window.open('https://docs.google.com/gview?url=https://github.com/angshul004/notecenter/raw/main/sdg.pdf&embedded=true', '_blank');
}
