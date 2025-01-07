document.getElementById('toggleButton').addEventListener('click', function() {
    var modules = document.getElementById('modules');
    modules.classList.toggle('show');
});

// View PDF
var buttons = document.querySelectorAll('.viewButton');
buttons.forEach(function(button) {
    button.addEventListener('click', function() {
        var url = this.getAttribute('data-url');
        openPDF(url);
    });
});

function openPDF(url) {
    let newWindow = window.open(url, '_blank');
    newWindow.onload = function() {
        setTimeout(() => {
            // Check if the page is blank or contains minimal content
            if (!newWindow.document.body || newWindow.document.body.innerHTML.trim().length === 0) {
                newWindow.location.reload();
            }
        }, 1500); // Check after 1.5 seconds
    };
}
