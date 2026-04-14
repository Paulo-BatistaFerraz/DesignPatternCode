"""
30-Second Interval Timer with Urgent Alarm
------------------------------------------
Counts down 30 seconds, then blasts an escalating "MOVE!" alarm.
Repeats forever until you press Ctrl+C.
 
Requirements:
    pip install pygame numpy
"""
 
import time
import sys
import numpy as np
import pygame
 
# ── Settings ──────────────────────────────────────────────────────────────────
INTERVAL_SECONDS = 30       # How long each interval lasts
SAMPLE_RATE      = 44100    # Audio sample rate (Hz)
 
# ── Audio helpers ──────────────────────────────────────────────────────────────
 
def make_tone(freq: float, duration: float, volume: float = 0.8, sample_rate: int = SAMPLE_RATE) -> np.ndarray:
    """Generate a sine-wave tone as a NumPy array (int16)."""
    t = np.linspace(0, duration, int(sample_rate * duration), endpoint=False)
    wave = np.sin(2 * np.pi * freq * t)
    # Quick fade-out to avoid clicking
    fade_samples = min(int(sample_rate * 0.01), len(wave))
    wave[-fade_samples:] *= np.linspace(1, 0, fade_samples)
    return (wave * volume * 32767).astype(np.int16)
 
 
def build_alarm(sample_rate: int = SAMPLE_RATE) -> np.ndarray:
    """
    Build an escalating 'MOVE!' alarm:
    • 3 short rising-pitch beeps (urgency cue)
    • A long high-pitched burst
    Total duration ≈ 2 seconds.
    """
    silence = np.zeros(int(sample_rate * 0.05), dtype=np.int16)
 
    # Three rapid escalating beeps
    beep1 = make_tone(600,  0.12, volume=0.2)
    beep2 = make_tone(900,  0.12, volume=0.5)
    beep3 = make_tone(1200, 0.12, volume=0.5)
 
    # Long urgent blast
    blast = make_tone(1400, 0.55, volume=0.7)
 
    # Short gap then a second blast (double-punch feeling)
    gap   = np.zeros(int(sample_rate * 0.08), dtype=np.int16)
    blast2 = make_tone(1600, 0.35, volume=0.7)
 
    return np.concatenate([beep1, silence, beep2, silence, beep3, silence, blast, gap, blast2])
 
 
def play_array(arr: np.ndarray, sample_rate: int = SAMPLE_RATE) -> None:
    """Play a NumPy int16 array through pygame."""
    stereo = np.column_stack([arr, arr])  # pygame needs stereo
    sound  = pygame.sndarray.make_sound(stereo)
    sound.play()
    pygame.time.wait(int(sound.get_length() * 1000) + 50)  # wait until done
 
 
# ── Main loop ─────────────────────────────────────────────────────────────────
 
def run_timer():
    pygame.mixer.init(frequency=SAMPLE_RATE, size=-16, channels=2, buffer=512)
    alarm = build_alarm()
 
    print("━" * 45)
    print("  ⏱  30-Second Interval Timer  ⏱")
    print("  Press Ctrl+C to stop.")
    print("━" * 45)
 
    interval = 1
    try:
        while True:
            # ── Countdown ──────────────────────────────────────────
            for remaining in range(INTERVAL_SECONDS, 0, -1):
                bar_len   = 30
                filled    = bar_len - int((remaining / INTERVAL_SECONDS) * bar_len)
                bar       = "█" * filled + "░" * (bar_len - filled)
                sys.stdout.write(
                    f"\r  Interval {interval:>3}  [{bar}]  {remaining:>2}s remaining  "
                )
                sys.stdout.flush()
                time.sleep(1)
 
            # ── ALARM ──────────────────────────────────────────────
            sys.stdout.write(
                f"\r  Interval {interval:>3}  [{'█' * 30}]  🔔 MOVE! MOVE! MOVE!          \n"
            )
            sys.stdout.flush()
            play_array(alarm)
            interval += 1
 
    except KeyboardInterrupt:
        print("\n\n  Timer stopped. Great work! 💪")
        pygame.mixer.quit()
 
 
if __name__ == "__main__":
    run_timer()