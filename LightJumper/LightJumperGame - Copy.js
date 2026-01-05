const character = document.getElementById('character');
let characterPosition = 20; // Starting position of the character (in percentage)
let characterTopPosition = 50; // Vertical position of the character (in percentage)
let step = 1; // Number of percentage steps the character moves horizontally
let gravity = 0.01; // Gravity force
let velocity = 0; // Vertical velocity (affects fall speed)
let jumpHeight = 15; // Height to jump (percentage of screen height)
let isJumping = false;

document.addEventListener('keydown', function(event) {
    let newPosition = characterPosition;

    if (event.key === 'ArrowLeft') {
        // Move the character left
        newPosition -= step;
        if (newPosition < 0) {
            newPosition = 0; // Prevent moving out of the screen
        }
    } else if (event.key === 'ArrowRight') {
        // Move the character right
        newPosition += step;
    } 

    if (event.key === 'ArrowUp' && !isJumping) {
        characterTopPosition -= jumpHeight;
        isJumping = true;
    }

    // Check if the new position will land on a black background horizontally
    if (!willMoveIntoBlack(newPosition)) {
        characterPosition = newPosition;
        character.style.left = characterPosition + '%';
    }
});

// Game loop to always apply gravity to the character
function gameLoop() {
    // Apply gravity unless something black is below
    if (!willMoveIntoBlackVertically()) {
        velocity += gravity; // Apply gravity (increasing fall speed)
    } else {
        velocity = 0; // Stop falling if there is black below
        isJumping = false;
    }

    // Update the vertical position of the character
    characterTopPosition += velocity;

    // Apply the new vertical position to the character
    character.style.top = characterTopPosition + '%';

    // Request the next frame of the game loop
    requestAnimationFrame(gameLoop);
}

// Set interval to check the ground more often (e.g., every 10ms)
setInterval(() => {
    // You can check the ground more frequently here
    if (isFalling()) {
        checkGroundMoreFrequent();
    }
}, 5); // 10 milliseconds = 100Hz ground check (more frequent)

function isFalling() {
    return velocity > 0; // Character is falling if velocity is positive
}

function checkGroundMoreFrequent() {
    // Check the ground more frequently (beyond normal game loop)
    if (willMoveIntoBlackVertically()) {
        // If the character is close to the ground, apply landing logic
        velocity = 0;
        isJumping = false;
    }
}

gameLoop();

// Function to check the color at the new position where the character will move horizontally
function getColorAtNewPosition(newPosition, isVertical = false) {
    const characterRect = character.getBoundingClientRect();

    if (isVertical) {
        // For vertical check, use the character's center position but adjust for height
        const targetX = characterRect.left + characterRect.width / 2;
        const targetY = characterTopPosition * window.innerHeight / 100 + characterRect.height / 2;
        const targetElement = document.elementFromPoint(targetX, targetY);
        return getBackgroundColor(targetElement); // Return the background color of the element
    } else {
        // Horizontal check
        const targetX = (newPosition * window.innerWidth) / 100 + characterRect.width / 2;
        const targetY = characterRect.top + characterRect.height / 2;
        const targetElement = document.elementFromPoint(targetX, targetY);
        return getBackgroundColor(targetElement);
    }
}

// Function to get the background color of an element
function getBackgroundColor(element) {
    if (element) {
        const backgroundColor = window.getComputedStyle(element).backgroundColor;
        return backgroundColor; // Return the background color as a string
    }
    return 'transparent'; // Return transparent if no element found
}

// Function to check if the new position will overlap a black background horizontally
function willMoveIntoBlack(newPosition) {
    const characterRect = character.getBoundingClientRect();
    const targetX = (newPosition * window.innerWidth) / 100 + characterRect.width / 2;
    const targetY = characterRect.top + characterRect.height / 2;
    const targetElement = document.elementFromPoint(targetX + 23, targetY - 23);
    return isBlackBackground(targetElement);
}

// Function to check if the new position will overlap a black background vertically (for gravity)
function willMoveIntoBlackVertically() {
    const characterRect = character.getBoundingClientRect();
    const targetX = characterRect.left + characterRect.width / 2;
    const targetY = (characterTopPosition + 5) * window.innerHeight / 100 + characterRect.height / 2; // Small offset to check just below the character
    const targetElement = document.elementFromPoint(targetX, targetY);
    return isBlackBackground(targetElement);
}

// Function to check if an element has a black background
function isBlackBackground(element) {
    const backgroundColor = getBackgroundColor(element);
    return backgroundColor === 'rgb(0, 0, 0)'; // Check for black background
}

// Añade un listener para detectar clics en cualquier parte del documento
document.addEventListener('click', function (event) {
    // Crear un nuevo div para el cuadro
    const box = document.createElement('div');
    box.classList.add('box');

    // Establecer posición inicial del cuadro donde se hizo clic
    box.style.left = `${event.clientX}px`;
    box.style.top = `${event.clientY}px`;

    // Añadir el cuadro al contenedor del juego
    document.querySelector('.game-container').appendChild(box);

    // Añadir animación para que el cuadro caiga
    setTimeout(() => {
        box.style.top = '100%';
    }, 10);

    // Eliminar el cuadro después de que caiga (por ejemplo, tras 5 segundos)
    setTimeout(() => {
        box.remove();
    }, 5000);
});
