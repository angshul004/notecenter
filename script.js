document.getElementById('toggleButton').addEventListener('click', function() {
    var modules = document.getElementById('modules');
    modules.classList.toggle('show');
});

function openPDF() {
    window.open('pdfviewer.html', '_blank');
}
