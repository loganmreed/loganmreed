let originalHeight;
let isDownPressed = false;
let isJumping = false;
let gravity = 1; // Gravity force
let gameInterval;
let boxInterval1;
let boxInterval2;
let isGameOver = false;
let isPaused = false;
let boxSpeed = 10; // Box speed
let platformSpeed = 5;
let platforms = [];
let boxes = []; // Array track all boxes
let animationFrameId; // Track requestAnimationFrame ID
let canJump = true; // Jump delay variable
let spawnRateBoxes1 = 2000;
let spawnRateBoxes2 = 3000;
let spawnRatePlatforms = 5000;
let spawnChancePlatforms = 0.7;
let score = 0;
let jumpStrength = -20;
let PlatformHight = 50;
const HIGH_SCORES_KEY = 'highScores';

// Load high scores
function loadHighScores() {
    try {
        const storedScores = localStorage.getItem(HIGH_SCORES_KEY);
        return storedScores ? JSON.parse(storedScores) : [];
    } catch (e) {
        console.error('Failed to load high scores:', e);
        return [];
    }
}

// save high scores
function saveHighScores(scores) {
    try {
        localStorage.setItem(HIGH_SCORES_KEY, JSON.stringify(scores));
    } catch (e) {
        console.error('Failed to save high scores:', e);
    }
}

function promptForInitials() {
    let initials = '';
    while (!/^[A-Za-z]{2}$/.test(initials)) {
        initials = prompt('Enter your initials (exactly 2 alphabetic characters):');
        if (initials === null) return null; // Cancel input
    }
    return initials.toUpperCase();
}

// add new score
function addHighScore(score, initials, difficulty) {
    const highScores = loadHighScores();
    highScores.push({ score, initials, difficulty });
    highScores.sort((a, b) => b.score - a.score); // Sort scores descending
    if (highScores.length > 10) highScores.pop(); // Top 10 only
    saveHighScores(highScores);
}
function handleGameOver() {
    isGameOver = true;
    clearInterval(gameInterval);
    clearInterval(boxInterval1);
    clearInterval(boxInterval2);

    // Get player initials if they qualify
    const initials = promptForInitials();
    if (initials) {
        const difficulty = document.body.className;
        addHighScore(score, initials, difficulty);
    }

    // Show high scores
    displayHighScores();
}

function displayHighScores() {
    const highScores = loadHighScores();
    const leaderboard = document.getElementById('leaderboard');
    leaderboard.innerHTML = ''; // Clear leaderboard

    // Create leaderboard container
    const container = document.createElement('div');
    container.style.width = '40%';
    container.style.height = '55%';
    container.style.border = '1vw solid #000000';
    container.style.paddingRight = '2vw';
    container.style.paddingLeft = '2vw';
    container.style.borderRadius = '2vw';
    container.style.backgroundColor = '#f9f9f9';
    container.style.boxShadow = '0 4px 8px rgba(0, 0, 0, 0.2)';
    container.style.margin = '2vw 2vh';
    container.style.textAlign = 'center';
    container.style.fontFamily = '"Roboto", sans-serif';

    // Leaderboard title
    const title = document.createElement('h2');
    title.textContent = 'Leaderboard';
    title.style.color = '#000000';
    title.style.marginTop = '1vh';
    title.style.marginBottom = '1vh';
    title.style.textShadow = '1px 1px 3px rgba(0, 0, 0, 0.3)';

    container.appendChild(title);

    // list of scores
    const list = document.createElement('ol');
    highScores.forEach((entry, index) => {
        const item = document.createElement('li');

        // Rank-based background color
        if (index === 0) {
            item.style.backgroundColor = 'gold';
        } else if (index === 1) {
            item.style.backgroundColor = 'silver';
        } else if (index === 2) {
            item.style.backgroundColor = '#cd7f32'; 
        } else {
            item.style.backgroundColor = index % 2 === 0 ? '#C0C0C0' : '#ffffff';
        }

        item.style.padding = '1vh';
        item.style.borderRadius = '1vh';
        item.style.marginBottom = '1vh';
        item.style.boxShadow = '0 2px 4px rgba(0, 0, 0, 0.1)';
        item.style.fontSize = '1.6vw';
        item.style.fontWeight = 'bold';

        const scoreDetails = document.createElement('span');
        scoreDetails.textContent = `${entry.initials} - ${entry.score} (${entry.difficulty})`;
        scoreDetails.style.color = '#333';
        scoreDetails.style.fontFamily = '"Roboto Mono", monospace';
        item.appendChild(scoreDetails);

        list.appendChild(item);
    });

    container.appendChild(list);
    leaderboard.appendChild(container);
    leaderboard.style.position = 'relative';
    leaderboard.style.zIndex = 1001;
    leaderboard.style.display = 'block';

}

function resetHighScores() {
    localStorage.removeItem(HIGH_SCORES_KEY);
    alert('High scores have been reset!');
}

function setJoystickPosition(bottom, left) {
    document.documentElement.style.setProperty('--joystick-bottom', `${bottom}px`);
    document.documentElement.style.setProperty('--joystick-left', `${left}px`);
}

function setButtonPosition(bottom, left) {
    document.documentElement.style.setProperty('--button-bottom', `${bottom}px`);
    document.documentElement.style.setProperty('--button-left', `${left}px`);
}

document.addEventListener('DOMContentLoaded', function () {
    // Detect mobile/tablet
    const isMobile = /Mobi|Android/i.test(navigator.userAgent);
    isMobileOrTablet = isMobile;
    if (isMobile) {
        const mobileControls = document.getElementById('mobileControls');
        mobileControls.style.display = 'flex';

        // Simulate right button
        const rightButton = document.getElementById('rightButton');
        rightButton.addEventListener('click', () => {
            const event = new KeyboardEvent('keydown', { key: 'ArrowRight' });
            document.dispatchEvent(event);
        });

        // Simulate joystick
        const joystick = document.getElementById('joystick');
        const joystickHandle = document.getElementById('joystickHandle');

        let joystickCenter = { x: 0, y: 0 };
        joystick.addEventListener('touchstart', (e) => {
            const rect = joystick.getBoundingClientRect();
            joystickCenter = { x: rect.left + rect.width / 2, y: rect.top + rect.height / 2 };
        });

        joystick.addEventListener('touchmove', (e) => {
            e.preventDefault();
            const touch = e.touches[0];
            const deltaX = touch.clientX - joystickCenter.x;
            const deltaY = touch.clientY - joystickCenter.y;

            // Move joystick handle
            joystickHandle.style.transform = `translate(${Math.min(Math.max(deltaX, -30), 30)}px, ${Math.min(Math.max(deltaY, -30), 30)}px)`;

            /// Simulate arrow keys
            if (deltaY < -20) {
                const upEvent = new KeyboardEvent('keydown', { key: 'ArrowUp' });
                document.dispatchEvent(upEvent);
            } else if (deltaY > 20) {
                const downEvent = new KeyboardEvent('keydown', { key: 'ArrowDown' });
                document.dispatchEvent(downEvent);
            }
        });

        joystick.addEventListener('touchend', () => {
            // Reset joystick handle position
            joystickHandle.style.transform = 'translate(0, 0)';
        
            // Release down arrow
            const downReleaseEvent = new KeyboardEvent('keyup', { key: 'ArrowDown' });
            document.dispatchEvent(downReleaseEvent);
        
            // Release up arrow
            const upReleaseEvent = new KeyboardEvent('keyup', { key: 'ArrowUp' });
            document.dispatchEvent(upReleaseEvent);
        });        
    }
});

document.addEventListener('DOMContentLoaded', function() {
    const themeSelect = document.getElementById('themeSelect');

    // Detect mobile/tablet
    function isMobileOrTablet() {
        return /Mobi|Android|iPad|iPhone/i.test(navigator.userAgent);
    }

    // Restrict to "default" theme on mobile/tablet
    if (isMobileOrTablet()) {
        document.body.classList.add('default');
        localStorage.setItem('selectedTheme', 'default');

        // Disable dropdown to "default"
        themeSelect.value = 'default';
        themeSelect.disabled = true;
    } else {
        // Load theme on non-mobile/tablet
        const savedTheme = localStorage.getItem('selectedTheme');
        if (savedTheme) {
            document.body.classList.add(savedTheme);
            themeSelect.value = savedTheme; // Sync dropdown with saved theme
        }

        // Update the theme and save it to localStorage
        themeSelect.addEventListener('change', function() {
            // Remove all theme-related classes from the body
            document.body.classList.remove('default', 'dark', 'space', 'forest');

            // Add the selected theme class
            const selectedTheme = themeSelect.value;
            document.body.classList.add(selectedTheme);

            // Save the selected theme to localStorage
            localStorage.setItem('selectedTheme', selectedTheme);
        });
    }
});

function logBoxSpeed() {
    console.log('Box Speed:', boxSpeed, 'spawnRateBoxes1', spawnRateBoxes1);
}

function resetGame() {
    location.reload();
    document.getElementById('gameOverPopup').style.display = 'none';
    startGame();
}

function updateScore() {
    score += 1;
    if (score % 20 === 0 && score !== 0) {
        boxSpeed += 1;
        spawnRateBoxes1 -= 1;
        spawnRateBoxes2 -= 1;
        spawnRatePlatforms += 5;
    }    
    document.getElementById('score').innerText = `Score: ${score} : Level: ${Math.ceil(score / 20)}`;
}

document.addEventListener('DOMContentLoaded', function() {
    const themeSelect = document.getElementById('themeSelect');
    
    themeSelect.addEventListener('change', function() {
        // Remove all theme-related classes from the body
        document.body.classList.remove('default', 'dark', 'light', 'space', 'vintage', 'forest');
        
        // Add the selected theme class
        const selectedTheme = themeSelect.value;
        document.body.classList.add(selectedTheme);
    });
});

document.addEventListener('DOMContentLoaded', function() {
    const player = document.querySelector('.player');
    const pauseText = document.querySelector('.pause-text');
    const gameOverPopup = document.getElementById('gameOverPopup');
    const restartButton = document.getElementById('restartButton');
    const startMenu = document.getElementById('startMenu');
    const easyButton = document.getElementById('easyButton');
    const mediumButton = document.getElementById('mediumButton');
    const hardButton = document.getElementById('hardButton');
    const viewportHeight = window.innerHeight;
    const scaleFactor = (viewportHeight / 954)*1.25;
    const isMobile = /Mobi|Android/i.test(navigator.userAgent);

    document.getElementById('score').innerText = `Score: ${score} : Level: ${Math.ceil(score / 20)}`;
    originalHeight = parseInt(window.getComputedStyle(player).getPropertyValue('height'));

    let playerY = window.innerHeight - ((window.innerHeight * 5) / 100);
    let velocity = 0; // Initial velocity

    // Add event listeners for difficulty buttons
    easyButton.addEventListener('click', () => startGame('Easy'));
    mediumButton.addEventListener('click', () => startGame('Medium'));
    hardButton.addEventListener('click', () => startGame('Hard'));

    function startGame(difficulty = 'Medium') {
        // Set box speed based on difficulty
        switch (difficulty) {
            case 'Easy':
                if (isMobile) {
                    // Mobile or tablet settings (Easy)
                    boxSpeed = 10 * (1 + (scaleFactor / 12));
                    gravity = 1 * (1 + (scaleFactor / 10));
                    jumpStrength = -25 * scaleFactor;
                    console.log("jumpStrength: ", jumpStrength, "scale factor:", scaleFactor);
                    platformSpeed = 10;
                    spawnRateBoxes1 = 2000;
                    spawnRateBoxes2 = 3000;
                    spawnRatePlatforms = 30000;
                    spawnChancePlatforms = 0.0;//defalult 0.8
                    PlatformHight = 50;
                } else {
                    // Computer settings
                    boxSpeed = 10;
                    gravity = 1.2;
                    jumpStrength = -25;
                    platformSpeed = 10;
                    spawnRateBoxes1 = 2000;
                    spawnRateBoxes2 = 3000;
                    spawnRatePlatforms = 300000;
                    spawnChancePlatforms = 0.0; //default 0.5
                    PlatformHight = 50;
                }
            case 'Medium':
                boxSpeed = 15;
                gravity = 1.2;
                jumpStrength = -25;
                platformSpeed = 50;
                spawnRateBoxes1 = 1700;
                spawnRateBoxes2 = 2700;
                spawnRatePlatforms = 5300;
                spawnChancePlatforms = 0.2;
                PlatformHight = 100;
                break;
            case 'Hard':
                boxSpeed = 10;
                gravity = 1;
                jumpStrength = -25;
                platformSpeed = 8;
                spawnRateBoxes1 = 2500;
                spawnRateBoxes2 = 3000;
                spawnRatePlatforms = 25000;
                spawnChancePlatforms = 0.6;
                PlatformHight = 50;
                break;
        }

        // Hide the start menu
        startMenu.style.display = 'none';

        gameInterval = setInterval(applyGravity, 20); // Update gravity every 20ms
        boxInterval1 = setInterval(() => spawnBox(), spawnRateBoxes1); // Spawn a box every 2000 milliseconds
        boxInterval2 = setInterval(() => spawnBox(), spawnRateBoxes2); // Spawn another box every 3000 milliseconds
        platformInterval = setInterval(() => {
            if (Math.random() < spawnChancePlatforms) {
                spawnPlatform();
            }
        }, spawnRatePlatforms);
        logBoxSpeed(); // Log the box speed
        updateBoxes(); // Start moving boxes
    }

    function applyGravity() {
        velocity += gravity;
        playerY += velocity;
        const scalingFactor = window.innerHeight / 100; // 1vh = 1% of viewport height
        const floorOffset = 5 * scalingFactor; // Equivalent to 5vh
        
        // Calculate floorY with dynamic scaling
        const floorY = window.innerHeight - (isDownPressed ? originalHeight * 0.5 : originalHeight) - floorOffset;
        
        const ceilingY = floorOffset; // Assuming the ceiling height is 50px
    
        platforms.forEach(platform => {
            const platformRect = platform.getBoundingClientRect();
            const playerRect = player.getBoundingClientRect();
    
            // Collision from above (landing on the platform)
            if (
                playerRect.bottom <= platformRect.top &&
                playerRect.bottom + velocity >= platformRect.top &&
                playerRect.right > platformRect.left &&
                playerRect.left < platformRect.right
            ) {
                playerY = platformRect.top - playerRect.height;
                velocity = 0; // Stop falling
                isJumping = false; // Reset jumping state when on the platform
            }
    
            // Collision from below (hitting the bottom of the platform)
            if (
                playerRect.top >= platformRect.bottom &&
                playerRect.top + velocity <= platformRect.bottom &&
                playerRect.right > platformRect.left &&
                playerRect.left < platformRect.right
            ) {
                playerY = platformRect.bottom;
                velocity = 0; // Stop moving upward
                isJumping = false; // Reset jumping state when hitting the platform
            }
        });
    
        if (gravity > 0 && playerY >= floorY) { // Check for floor collision when gravity is positive
            playerY = floorY;
            velocity = 0; // Stop falling when hitting the floor
            isJumping = false; // Reset jumping state when on the ground
        } else if (gravity < 0 && playerY <= ceilingY) { // Check for ceiling collision when gravity is negative
            playerY = ceilingY;
            velocity = 0; // Stop moving when hitting the ceiling
            isJumping = false; // Reset jumping state when on the ceiling
        }
    
        // Hard stop: Ensure player does not overlap floor or ceiling
        if (playerY > floorY) {
            playerY = floorY;
            velocity = 0;
            isJumping = false;
        } else if (playerY < ceilingY) {
            playerY = ceilingY;
            velocity = 0;
            isJumping = false;
        }
    
        player.style.top = `${playerY}px`;
    }    
    function spawnPlatform() {
        const platform = document.createElement('div');
        platform.className = 'platform';
        platform.style.position = 'absolute';
        platform.style.width = '100%'; // Full width
        platform.style.height = `${PlatformHight}px`;
        platform.style.backgroundColor = '#000000'; // Platform color
        platform.style.top = `${window.innerHeight / 2}px`; // Middle of the screen
        platform.style.left = `${window.innerWidth}px`; // Start from the right edge
        document.body.appendChild(platform);
        platforms.push(platform); // Add the platform to the array of platforms
    }
    
    function movePlatforms() {
        platforms.forEach(platform => {
            let platformX = parseInt(window.getComputedStyle(platform).getPropertyValue('left'));
            platformX -= platformSpeed; // Move the platform to the left
            platform.style.left = `${platformX}px`;
    
            if (platformX + platform.clientWidth <= 0) {
                platforms = platforms.filter(p => p !== platform); // Remove the platform from the array
                platform.remove(); // Remove the platform from the DOM
            }
        });
    }    

    function spawnBox() {
        // Function to create a box at a given height
        const createBox = (height) => {
            const box = document.createElement('div');
            box.className = 'box';
            box.style.position = 'absolute';
            box.style.width = '4vw'; // Width as a percentage of viewport width
            box.style.height = '13vh'; // Height as a percentage of viewport height
            box.style.background = 'radial-gradient(circle, #00ff00 30%, #00b300 70%)';
            box.style.right = '0'; // Position it at the far right
            box.style.top = `${height}vh`; // Position it as a percentage of viewport height
            document.body.appendChild(box);
            boxes.push(box); // Add the box to the array of boxes
        };
    
        // Determine the mandatory box height
        let mandatoryHeight;
        if (Math.random() < 0.5) {
            // Near the floor with specific heights as percentages of viewport height
            const floorHeights = [75, 82]; // Adjusted to percentages (e.g., 75vh, 82vh)
            mandatoryHeight = floorHeights[Math.floor(Math.random() * floorHeights.length)];
        } else {
            // Near the ceiling with specific heights as percentages of viewport height
            const ceilingHeights = [5, 13]; // Adjusted to percentages (e.g., 5vh, 13vh)
            mandatoryHeight = ceilingHeights[Math.floor(Math.random() * ceilingHeights.length)];
        }
        createBox(mandatoryHeight);
    }    

    function moveBoxes() {
        boxes.forEach(box => {
            let boxX = parseInt(window.getComputedStyle(box).getPropertyValue('right'));
            boxX += boxSpeed; // Move the box
            box.style.right = `${boxX}px`;

            if (boxX >= window.innerWidth) {
                boxes = boxes.filter(b => b !== box); // Remove the box from the array
                updateScore();
                box.remove(); // Remove the box from the DOM
            }
        });
    }
    
    function checkCollision() {
        const playerRect = player.getBoundingClientRect();
        boxes.forEach(box => {
            const boxRect = box.getBoundingClientRect();
            if (
                playerRect.left < boxRect.right &&
                playerRect.right > boxRect.left &&
                playerRect.top < boxRect.bottom &&
                playerRect.bottom > boxRect.top
            ) {
                // Collision detected
                console.log('Collision detected!');
                handleGameOver()
                stopGame(); // Stop the game or take other actions
                gameOverPopup.style.display = 'block';
                boxes.forEach(box => box.remove());
                boxes = [];
                platforms = [];
            }
        });
    }

    function stopGame() {
        clearInterval(gameInterval);
        clearInterval(boxInterval1);
        clearInterval(boxInterval2);
        clearInterval(platformInterval);
        cancelAnimationFrame(animationFrameId); // Cancel the animation frame
        logBoxSpeed(); // Log the box speed
    }

    function updateBoxes() {
        if (!isPaused) {
            moveBoxes();
            movePlatforms();
            checkCollision(); // Check for collisions
        }
        animationFrameId = requestAnimationFrame(updateBoxes); // Keep updating the boxes
    }

    document.addEventListener('keydown', function(event) {
        const step = 10; // Number of pixels to move per step
        const left = parseInt(window.getComputedStyle(player).getPropertyValue('left'));

        if ((event.key === 'ArrowLeft' || event.key === 'ArrowRight') && !isJumping) {
            gravity = -gravity; // Reverse gravity
            updateEyePosition(); // Update eye position when gravity is reversed
            canJump = false; // Disable jumping temporarily
            setTimeout(() => {
                canJump = true; // Re-enable jumping after delay
            }, 500); // 500 milliseconds delay
        } else if (event.key === 'ArrowDown') {
            const currentHeight = parseInt(window.getComputedStyle(player).getPropertyValue('height'));
            if (currentHeight === originalHeight) {
                player.style.height = `${currentHeight / 2}px`;
                isDownPressed = true;
                updateEyePosition(); // Update eye position when height is halved
            }
        } else if (event.key === 'ArrowUp' && !isJumping && canJump) {
            velocity = (gravity > 0) ? jumpStrength : -jumpStrength; // Invert jump direction based on gravity
            isJumping = true;
        } else if (event.key === 'p') {
            isPaused = !isPaused; // Toggle pause state
            if (isPaused) {
                stopGame(); // Pause the game
                pauseText.style.display = 'block'; // Show pause text
            } else {
                startGame(); // Resume the game
                pauseText.style.display = 'none'; // Hide pause text
            }
        }
    });

    document.addEventListener('keyup', function(event) {
        if (event.key === 'ArrowDown') {
            player.style.height = `${originalHeight}px`; // Reset to original height
            isDownPressed = false;
            updateEyePosition(); // Update eye position when height is reset

            // Adjust position if player is inside the floor
            const playerY = parseInt(window.getComputedStyle(player).getPropertyValue('top'));
            const floorY = window.innerHeight - originalHeight - 50;
            if (playerY >= floorY) {
                player.style.top = `${floorY}px`;
            }
        }
    });

    function updateEyePosition() {
        const leftEye = document.querySelector('.left-eye');
        const rightEye = document.querySelector('.right-eye');
        
        // Use dynamic positioning based on viewport height (vh)
        const normalPosition = '3.5vh'; // Equivalent to ~5% of the viewport height
        const reversedPosition = '5vh'; // Equivalent to ~15% of the viewport height
    
        if (isDownPressed) {
            if (gravity > 0) {
                leftEye.style.top = normalPosition; // Normal position
                rightEye.style.top = normalPosition;
            } else {
                leftEye.style.top = normalPosition; // Reversed but same height
                rightEye.style.top = normalPosition;
            }
        } else {
            if (gravity > 0) {
                leftEye.style.top = normalPosition; // Normal position
                rightEye.style.top = normalPosition;
            } else {
                leftEye.style.top = reversedPosition; // Move eyes down when gravity is reversed
                rightEye.style.top = reversedPosition;
            }
        }
    }
    

    restartButton.addEventListener('click', function() {
        resetGame();
    });

});
