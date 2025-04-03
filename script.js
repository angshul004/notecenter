//dropdown anime
document.querySelectorAll('.subject').forEach(function(subject) {
    var toggleButton = subject.querySelector('.toggleButton');
    var modules = subject.querySelector('.modules');

    toggleButton.addEventListener('click', function() {
        if (modules.classList.contains('show')) {
            // Close the dropdown
            modules.style.maxHeight = '0';
        } else {
            // Open the dropdown
            modules.style.maxHeight = `${modules.scrollHeight}px`;
        }
        modules.classList.toggle('show');
        toggleButton.classList.toggle('rotated');
    });

    modules.addEventListener('transitionend', function() {
        if (!modules.classList.contains('show')) {
            modules.style.maxHeight = '';
        }
    });
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
    var maxAttempts = 7; // Maximum attempts
    var attempt = 0;
    var newWindow;

    function openWindow() {
        attempt++;
        if (attempt > maxAttempts) {
            console.error('Failed to load the URL');
            return;
        }

        if (attempt === 1) {
            newWindow = window.open(url, '_blank'); // First attempt using window.open
        } else {
            newWindow.location.href = url; // Reloading the window on subsequent attempts
        }

        if (!newWindow) {
            console.error('Window blocked. Please allow pop-ups.');
            return;
        }

        setTimeout(function() {
            if (newWindow.document.readyState === 'complete' && newWindow.document.body.innerHTML.trim() === '') {
                console.log('Content not loaded or window is blank. Trying again...');
                openWindow(); // Retry opening the window
            } else {
                console.log('PDF loaded successfully!');
            }
        }, 1700); // reload gap
    }

    openWindow();
}
