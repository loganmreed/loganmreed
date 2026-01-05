const character = document.getElementById('character');
const platform = document.getElementById('platform');
const gravity = 9.8; // Acceleration due to gravity
const floorY = platform.offsetTop; // Y position of the floor

// box grid and box details
const gridSizeX = 64; // Horizontal grid cell size (in pixels)
const gridSizeY = 72; // Vertical grid cell size (in pixels)
const boxWidth = 60; // Box width (in pixels)
const boxHeight = 70; // Box height (in pixels)
const marginBottomPercentage = 0.07; // 7% margin from the bottom of the screen
const screenHeight = window.innerHeight;
const marginBottom = screenHeight * marginBottomPercentage; // 7% margin from the bottom

// Calculate the number of rows considering the margin
const availableHeight = screenHeight - marginBottom; // Height excluding bottom margin
const rows = Math.floor(availableHeight / boxHeight); // Number of rows based on available height
const columns = Math.floor(window.innerWidth / gridSizeX); // Number of columns based on screen width

const occupied = Array(columns).fill(0); // Array to track the lowest available row in each column
const boxes = []; // Track all placed boxes
let skyPlatforms = [];

let keys = {}; // Track key states
let characterVelocity = { x: 0, y: 0 }; // Character's velocity
let characterMass = 10; // Player's mass
let onGround = true; // Whether the character is on the ground
let isStandingOnSomething = true; // Whether the character is on boxes

// Settings for movement
let speed = 5; // Base speed for movement
let airControlFactor = 0.5; // Reduced control when airborne

// Event listeners for movement
document.addEventListener('keydown', (e) => (keys[e.code] = true));
document.addEventListener('keyup', (e) => (keys[e.code] = false));

// Window resize listener
window.addEventListener('resize', adjustSpeed);

// Update loop
function gameLoop() {
    checkCollisions();
    handleCharacterMovement();
    checkCollisions();
    applyPhysics();
    updateCharacterPosition();
    requestAnimationFrame(gameLoop);
}

// Handle character movement based on key inputs
function handleCharacterMovement() {
  if (keys['ArrowLeft']) {
    characterVelocity.x = onGround ? -speed : -speed * airControlFactor;
    character.classList.add('walking-x');
    character.style.transform = 'rotateY(70deg)';
  } else if (keys['ArrowRight']) {
    characterVelocity.x = onGround ? speed : speed * airControlFactor;
    character.classList.add('walking-x');
    character.style.transform = 'rotateY(-70deg)';
  } else {
    characterVelocity.x = 0;
    character.classList.remove('walking-x');
    character.style.transform = 'rotateY(45deg)';
  }

  /* if (keys['Space'] && onGround) {
    characterVelocity.y = -20; // Stronger jump due to higher mass
    onGround = false;
  } */
}

// Apply physics to the character
function applyPhysics() {
    if (!isStandingOnSomething){
    //characterVelocity.y += gravity * characterMass * 0.016; // Simulate gravity
    characterVelocity.y += Math.floor(gravity * characterMass * 0.016);
    //characterVelocity.y += Math.ceil(gravity * characterMass * 0.016);
    }
}

// Update character's position based on velocity
function updateCharacterPosition() {
  const nextPosition = {
    x: character.offsetLeft + characterVelocity.x,
    y: character.offsetTop + characterVelocity.y,
  };

  // Check for landing (check if the character hits the floor)
  if (nextPosition.y + character.offsetHeight >= floorY) {
    nextPosition.y = floorY - character.offsetHeight;
    characterVelocity.y = 0;
    onGround = true;
  }

  // Update position
  character.style.left = `${nextPosition.x}px`;
  character.style.top = `${nextPosition.y}px`;
}

// Dynamically adjust character speed based on window width
function adjustSpeed() {
  speed = window.innerWidth / 200; // Adjust speed proportionally to window width
}

const MAX_CLIMB_HEIGHT = character.offsetHeight / 2; // height difference the character can climb

function checkCollisions() {
    const characterBounds = character.getBoundingClientRect();
    const characterBottom = characterBounds.bottom;
    const characterTop = characterBounds.top;
    const characterLeft = characterBounds.left;
    const characterRight = characterBounds.right;
  
    let standingOnSomething = false; // Track whether the character is standing on anything
  
    // Create a map to track the top box in each column
    const topBoxes = {};
  
    // First: Find the top box in each column
    boxes.forEach((box) => {
      const boxColumn = box.getAttribute('data-column');
      const boxBounds = box.getBoundingClientRect();
  
      // Update topBoxes if this box is the topmost one in its column
      if (
        !topBoxes[boxColumn] || 
        boxBounds.top < topBoxes[boxColumn].getBoundingClientRect().top
      ) {
        topBoxes[boxColumn] = box;
      }
    });
  
    // Second: Handle climbability, standing checks, and horizontal collision
    boxes.forEach((box) => {
      const boxColumn = box.getAttribute('data-column');
      const topBox = topBoxes[boxColumn];
      const boxBounds = box.getBoundingClientRect();
  
      // Mark boxes below the top box in their column as non-climbable
      if (box !== topBox) {
        box.setAttribute('data-isClimbable', false);
        box.classList.add('non-climbable');
  
        // Handle horizontal collision for non-climbable boxes
        if (
          characterBounds.right > boxBounds.left && // Character is to the left of the box
          characterBounds.left < boxBounds.right && // Character is to the right of the box
          characterBounds.bottom > boxBounds.top && // Character is vertically overlapping the box
          characterBounds.top < boxBounds.bottom
        ) {
          // Determine collision side (left or right)
          if (characterBounds.right > boxBounds.left && characterBounds.left < boxBounds.left) {
            // Collision on the left side of the box
            characterVelocity.x = -1;//characterVelocity.x = Math.min(characterVelocity.x, 0); // Stop leftward motion
            //character.style.left = `${boxBounds.left - character.offsetWidth}px`; // Align to the left
          } else if (characterBounds.left < boxBounds.right && characterBounds.right > boxBounds.right) {
            // Collision on the right side of the box
            characterVelocity.x = 1; Math.max(characterVelocity.x, 0); // Stop rightward motion
            //character.style.left = `${boxBounds.right}px`; // Align to the right
          }
        }
      } else {
        // Top box logic: Determine climbability and standing status
        const isClimbable =
          characterTop <= boxBounds.top &&
          boxBounds.top - characterTop <= MAX_CLIMB_HEIGHT;
  
        box.setAttribute('data-isClimbable', isClimbable);
  
        if (!isClimbable) {
          box.classList.add('non-climbable');
        } else {
          box.classList.remove('non-climbable');
        }
  
        // Handle collision with the climbable top box
        const isStandingOnBox =
          characterBottom >= boxBounds.top && // Character's bottom is aligned with the box's top
          characterBottom <= boxBounds.bottom + 5 && // Allow a small threshold for alignment
          characterRight > boxBounds.left && // Horizontally overlapping
          characterLeft < boxBounds.right;
  
        if (isStandingOnBox) {
          standingOnSomething = true;
  
          // Stop vertical movement
          characterVelocity.y = 0;
          onGround = true;
  
          // Align the character's bottom to the top of the box
          //character.style.top = `${boxBounds.top - character.offsetHeight}px`;
          character.style.top = `${Math.floor(boxBounds.top - character.offsetHeight)}px`;
        }
      }
    });
  
    // Update the `isStandingOnSomething` flag
    isStandingOnSomething = standingOnSomething;
  
    // If the character is not standing on anything, they should fall
    if (!standingOnSomething) {
      onGround = false;
    }
  }
  

document.body.addEventListener('click', function (event) {
  // Determine the column based on the click position
  const column = Math.floor(event.pageX / gridSizeX);

  // Find the lowest available row in the column
  const row = occupied[column];

  // If the column is not full (within the available height), create a new box
  if (row < rows) {
    const box = document.createElement('div');
    box.classList.add('box');

    // Set the position of the box in the grid (column and row)
    const x = column * gridSizeX;
    const y = screenHeight - marginBottom - (row + 1) * gridSizeY;

    box.style.left = `${x}px`;
    box.style.top = `${y}px`;

    box.setAttribute('data-column', column);

    document.body.appendChild(box);

    // Update the occupied row for that column
    occupied[column]++;
    boxes.push(box);
  }
});

document.querySelectorAll('*').forEach((element) => {
    element.addEventListener('contextmenu', function (event) {
        event.preventDefault();
    });
});

// Start the game loop
gameLoop();