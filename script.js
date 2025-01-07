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
    var maxAttempts = 5;
    var attempt = 0;

    function openWindow() {
        attempt++;
        if (attempt >= maxAttempts) {
            console.error('Failed to load the URL after ' + maxAttempts + ' attempts.');
            return;
        }

        var newWindow = window.open(url, '_blank');
        
        if (!newWindow) {
            console.error('Window blocked. Please allow pop-ups.');
            return;
        }

        setTimeout(function() {
            if (newWindow.document.body.innerHTML.trim() === '') {
                console.log('Content not loaded or window is blank. Trying again...');
                newWindow.location.href = url; 
            } else {
                console.log('PDF loaded successfully!');
            }
        }, 2000); // Adjust the timeout as needed
    }

    openWindow();
}
